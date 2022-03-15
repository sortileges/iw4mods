// ==========================================================
// 	MW2 Alpha 482 HUD
// 	by @simonlfc_
// ==========================================================

#define PREPROC_SHADER_DRAW( prect, pshader, pcolor, visArg ) \
		PREPROC_SHADER_DRAW_BASE( prect, pshader, pcolor, visArg, ; )

#define PREPROC_SHADER_DRAW_BASE( prect, pshader, pcolor, visArg, extraArgs ) \
		itemDef \
		{ \
			style 3 \
			rect prect \
			forecolor pcolor \
			exp material ( pshader ) \
			visible when ( visArg ) \
			decoration \
			extraArgs \
		}

#define PREPROC_TEXT_DRAW( prect, pfont, ptext, palign, psize, pcolor, visArg ) \
		PREPROC_TEXT_DRAW_BASE( prect, pfont, palign, ptext, psize, pcolor, visArg, ; )
		
#define PREPROC_TEXT_DRAW_BASE( prect, pfont, palign, ptext, psize, pcolor, visArg, extraArgs ) \
		itemDef \
		{ \
			rect prect \
			textfont pfont \
			textAlign palign \
			textScale psize \
			textstyle 6 \
			forecolor pcolor \
			exp text ( ptext ) \
			visible when ( visArg ) \
			decoration \
			extraArgs \
		}
		

#define TEAM_IS_MARINES			( localVarString( ui_team ) == "marines")
#define TEAM_IS_OPFOR			( localVarString( ui_team ) == "opfor")

#define NOT_SPECTATING 			( !spectatingClient() )
	
#define TEAM_IS_TIED			( team( score ) == otherteam( score ) )
#define TEAM_IS_WINNING 		( team( score ) > otherteam( score ) )
#define TEAM_IS_LOSING			( team( score ) < otherteam( score ) )
	
#define PLAYER_IS_TIED			( player( score ) == scoreatrank( 1 ) && scoreatrank( 1 ) == scoreatrank( 2 ) )
#define PLAYER_IS_WINNING		( player( score ) > scoreatrank( 2 ) )
#define PLAYER_IS_LOSING		( player( score ) < scoreatrank( 1 ) )
	
#define SHOULD_DISPLAY_SCOREBAR ( team( name ) != "TEAM_SPECTATOR" )

#define TEAM_BASED_GAMEMODE 	( !( ( team( "name" ) ) == "TEAM_FREE" ) )
#define NONTEAM_BASED_GAMEMODE 	( ( team( "name" ) ) == "TEAM_FREE" )

#define REGULAR_TIMER 	( secondsascountdown( ( int( timeleft( ) - ( ( dvarint( "ui_timelimit" ) ) ) * 0.5 * 60 * ( ( dvarint( "ui_halftime" ) ) && ( timeleft( ) + 1 > ( ( dvarint( "ui_timelimit" ) ) ) * 60 * 0.5 ) ) ) ) ) )
#define ORANGE_TIMER ( secondsascountdown( ( int( timeleft( ) - ( ( dvarint( "ui_timelimit" ) ) ) * 0.5 * 60 * ( ( dvarint( "ui_halftime" ) ) && ( timeleft( ) + 1 > ( ( dvarint( "ui_timelimit" ) ) ) * 60 * 0.5 ) ) ) ) ) )
#define RED_TIMER ( ( ( secondsascountdown ( int( timeleft( ) - ( ( dvarint( "ui_timelimit" ) ) ) * 0.5 * 60 * ( ( dvarint( "ui_halftime" ) ) && ( timeleft( ) + 1 > ( ( dvarint( "ui_timelimit" ) ) ) * 60 * 0.5 ) ) ) ) + "." + ( 9 - int( ( milliseconds( ) / 100 ) % 10 ) ) ) ) )

#define SCORE( alignArg, glowColour, textArg ) \
		itemDef \
		{ \
			rect 67 -32.6667 0.666667 0.666667 8 10 \
			decoration \
			visible 1 \
			glowColor glowColour \
			forecolor 0.85 0.855 0.85 1 \
			textFont 10 \
			textalign alignArg \
			textstyle 6 \
			textscale 0.3333 \
			visible when ( ( team( "name" ) != "TEAM_SPECTATOR" ) ) \
			exp text ( textArg ) \
		}

#define STATE( colourArg, textArg, visArg ) \
		itemDef \
		{ \
			rect		61 -44.6667 0.666667 0.666667 8 10 \
			text        textArg \
			visible		when ( ( ( ( milliseconds( ) % 30000 ) > 4000 && ( milliseconds( ) % 30000 ) < 30000 ) ) && visArg ) \
			textFont    9 \
			textscale	0.3333 \
			textalign	0 \
			textStyle   6 \
			forecolor	colourArg \
			decoration \
		}

#define TIMER( colourArg, glowColour, textArg, visArg ) \
		itemDef \
		{ \
			rect        228 -32 54.6667 54.6667 8 10 \
			exp text	( textArg ) \
			textfont	9 \
			textScale   0.3333 \
			textAlign   4 \
			textstyle	6 \
			visible		visArg \
			forecolor	colourArg \
			glowColor 	glowColour \
			decoration \
		}