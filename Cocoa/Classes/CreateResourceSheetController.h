#import <Cocoa/Cocoa.h>
#import <Carbon/Carbon.h>
#import "Resource.h"
#import "ResourceDataSource.h"

@interface CreateResourceSheetController : NSWindowController
{
	IBOutlet ResourceDataSource	*dataSource;
	IBOutlet NSMatrix 		*attributesMatrix;
	IBOutlet NSButton		*cancelButton;
	IBOutlet NSButton		*createButton;
	IBOutlet NSTextField	*nameView;
	IBOutlet NSTextField	*resIDView;
	IBOutlet NSTextField	*typeView;
	IBOutlet NSPopUpButton	*typePopup;
	IBOutlet NSWindow		*parent;
}

- (void)controlTextDidChange:(NSNotification *)notification;

- (IBAction)showCreateResourceSheet:(id)sender;
- (IBAction)hideCreateResourceSheet:(id)sender;
- (IBAction)typePopupSelection:(id)sender;

@end