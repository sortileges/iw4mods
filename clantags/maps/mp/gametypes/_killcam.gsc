// Since - I assume - people who want to use this are trickshotters who are using a modified version of this file, I'll let them edit theirs
// Below is the snippet you need to add. You need to add the lines 8 and 9 in that 'if' statement, which already exists
// You can use CTRL+F to search for the 'if' statement. This is how it needs to look like :

if ( isDefined( attacker ) && level.showingFinalKillcam )
{
	self openMenu( "killedby_card_display" );
	self setClientDvar("killedby_tag", attacker.tag);
	self setClientDvar("killedby_name", attacker.shortname);
	self SetCardDisplaySlot( attacker, 7 );
}