#import "CreateResourceSheetController.h"

@implementation CreateResourceSheetController

- (void)controlTextDidChange:(NSNotification *)notification
{
	BOOL enableButton = NO, clash = NO;
	NSString *type = [typeView stringValue];
	NSNumber *resID = [NSNumber numberWithInt:[resIDView intValue]];
	
	if( [type length] == 4 && [[resIDView stringValue] length] > 0 )
	{
		Resource *resource;
		NSEnumerator *enumerator = [[dataSource resources] objectEnumerator];
		while( resource = [enumerator nextObject] )
		{
			if( [type isEqualToString:[resource type]] && [resID isEqualToNumber:[resource resID]] )
				clash = YES;
		}
		if( !clash ) enableButton = YES;
	}
	[createButton setEnabled:enableButton];
}

- (IBAction)showCreateResourceSheet:(id)sender
{
	[NSApp beginSheet:[self window] modalForWindow:parent modalDelegate:self didEndSelector:NULL contextInfo:nil];
}

- (IBAction)hideCreateResourceSheet:(id)sender
{
	if( sender == createButton )
	{
		unsigned short attributes = 0;
		attributes ^= [[attributesMatrix cellAtRow:0 column:0] intValue]? resPreload:0;
		attributes ^= [[attributesMatrix cellAtRow:1 column:0] intValue]? resPurgeable:0;
		attributes ^= [[attributesMatrix cellAtRow:2 column:0] intValue]? resLocked:0;
		attributes ^= [[attributesMatrix cellAtRow:0 column:1] intValue]? resSysHeap:0;
		attributes ^= [[attributesMatrix cellAtRow:1 column:1] intValue]? resProtected:0;
		[dataSource addResource:[Resource resourceOfType:[typeView stringValue] andID:[NSNumber numberWithShort:(short) [resIDView intValue]] withName:[nameView stringValue] andAttributes:[NSNumber numberWithUnsignedShort:attributes]]];
	}
	[[self window] orderOut:nil];
	[NSApp endSheet:[self window]];
}

- (IBAction)typePopupSelection:(id)sender
{
	[typeView setStringValue:[typePopup titleOfSelectedItem]];
	[typeView selectText:sender];
}

@end
