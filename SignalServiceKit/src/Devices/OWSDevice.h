//
//  Copyright (c) 2019 Open Whisper Systems. All rights reserved.
//

#import "BaseModel.h"
#import <Mantle/MTLJSONAdapter.h>

NS_ASSUME_NONNULL_BEGIN

extern uint32_t const OWSDevicePrimaryDeviceId;

@class SDSAnyReadTransaction;
@class SDSAnyWriteTransaction;
@class SDSKeyValueStore;

@interface OWSDeviceManager : NSObject

+ (SDSKeyValueStore *)keyValueStore;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)sharedManager;

- (BOOL)mayHaveLinkedDevicesWithTransaction:(SDSAnyReadTransaction *)transaction;
- (void)setMayHaveLinkedDevices;
- (void)clearMayHaveLinkedDevices;

- (BOOL)hasReceivedSyncMessageInLastSeconds:(NSTimeInterval)intervalSeconds;
- (void)setHasReceivedSyncMessage;

@end

#pragma mark -

@interface OWSDevice : BaseModel <MTLJSONSerializing>

@property (nonatomic, readonly) NSInteger deviceId;
@property (nonatomic, readonly, nullable) NSString *name;
@property (nonatomic, readonly) NSDate *createdAt;
@property (nonatomic, readonly) NSDate *lastSeenAt;

- (instancetype)initWithUniqueId:(NSString *)uniqueId
                       createdAt:(NSDate *)createdAt
                        deviceId:(NSInteger)deviceId
                      lastSeenAt:(NSDate *)lastSeenAt
                            name:(nullable NSString *)name
NS_SWIFT_NAME(init(uniqueId:createdAt:deviceId:lastSeenAt:name:));

// --- CODE GENERATION MARKER

// This snippet is generated by /Scripts/sds_codegen/sds_generate.py. Do not manually edit it, instead run `sds_codegen.sh`.

// clang-format off

- (instancetype)initWithGrdbId:(int64_t)grdbId
                      uniqueId:(NSString *)uniqueId
                       createdAt:(NSDate *)createdAt
                        deviceId:(NSInteger)deviceId
                      lastSeenAt:(NSDate *)lastSeenAt
                            name:(nullable NSString *)name
NS_SWIFT_NAME(init(grdbId:uniqueId:createdAt:deviceId:lastSeenAt:name:));

// clang-format on

// --- CODE GENERATION MARKER

+ (nullable instancetype)deviceFromJSONDictionary:(NSDictionary *)deviceAttributes error:(NSError **)error;

/**
 * Set local database of devices to `devices`.
 *
 * This will create missing devices, update existing devices, and delete stale devices.
 * @param devices Removes any existing devices, replacing them with `devices`
 *
 * Returns YES if any devices were added or removed.
 */
+ (BOOL)replaceAll:(NSArray<OWSDevice *> *)devices transaction:(SDSAnyWriteTransaction *)transaction;

/**
 * The id of the device currently running this application
 */
+ (uint32_t)currentDeviceId;

/**
 *
 * @param transaction yapTransaction
 * @return
 *   If the user has any linked devices (apart from the device this app is running on).
 */
+ (BOOL)hasSecondaryDevicesWithTransaction:(SDSAnyReadTransaction *)transaction;

- (NSString *)displayName;
- (BOOL)isPrimaryDevice;

/**
 * Assign attributes to this device from another.
 *
 * @param other
 *  OWSDevice whose attributes to copy to this device
 * @return
 *  YES if any values on self changed, else NO
 */
- (BOOL)updateAttributesWithDevice:(OWSDevice *)other;

@end

NS_ASSUME_NONNULL_END
