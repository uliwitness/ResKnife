#import <Cocoa/Cocoa.h>

@class ResourceDocument, Resource;

/*!
@class			ResourceDataSource
@pending		This class needs to be made KVC compliant.
*/

@interface ResourceDataSource : NSObject
{
	IBOutlet NSOutlineView		*outlineView;
	IBOutlet NSWindow			*window;
	IBOutlet ResourceDocument	*document;
	
	NSMutableArray<Resource*>	*resources;
	NSMutableDictionary<NSString*,NSMutableArray<Resource*>*> *resourcesByType;
}

/*!
@method		window
*/
- (NSWindow *)window;

/*!
@method		resources
*/
- (NSArray *)resources;


-(NSDictionary*) resourcesByType;

/*!
@method		setResources:
*/
- (void)setResources:(NSMutableArray *)newResources;

/*!
@method		addResource:
*/
- (void)addResource:(Resource *)resource;

/*!
@method		removeResource:
*/
- (void)removeResource:(Resource *)resource;

/*!
@method		uniqueIDForType:
*/
- (NSNumber *)uniqueIDForType:(NSString *)type;

/*!
@method		defaultIDForType:
*/
- (NSNumber *)defaultIDForType:(NSString *)type;

/*!
@method		resourceOfType:andID:
*/
- (Resource *)resourceOfType:(NSString *)type andID:(NSNumber *)resID;

/*!
@method		resourceOfType:withName:
*/
- (Resource *)resourceOfType:(NSString *)type withName:(NSString *)name;

/*!
@method		allResourcesOfType:
*/
- (NSArray *)allResourcesOfType:(NSString *)type;

/*!
@method		allResourceIDsOfType:
*/
- (NSArray *)allResourceIDsOfType:(NSString *)type;

@end
