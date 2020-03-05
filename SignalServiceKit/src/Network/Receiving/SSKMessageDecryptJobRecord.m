//
//  Copyright (c) 2019 Open Whisper Systems. All rights reserved.
//

#import "SSKMessageDecryptJobRecord.h"

NS_ASSUME_NONNULL_BEGIN

@implementation SSKMessageDecryptJobRecord

- (instancetype)initWithEnvelopeData:(NSData *)envelopData label:(NSString *)label
{
    self = [super initWithLabel:label];
    if (!self) {
        return self;
    }

    _envelopeData = envelopData;

    return self;
}

// --- CODE GENERATION MARKER

// This snippet is generated by /Scripts/sds_codegen/sds_generate.py. Do not manually edit it, instead run `sds_codegen.sh`.

// clang-format off

- (instancetype)initWithGrdbId:(int64_t)grdbId
                      uniqueId:(NSString *)uniqueId
                    failureCount:(NSUInteger)failureCount
                           label:(NSString *)label
                          sortId:(unsigned long long)sortId
                          status:(SSKJobRecordStatus)status
                    envelopeData:(nullable NSData *)envelopeData
{
    self = [super initWithGrdbId:grdbId
                        uniqueId:uniqueId
                      failureCount:failureCount
                             label:label
                            sortId:sortId
                            status:status];

    if (!self) {
        return self;
    }

    _envelopeData = envelopeData;

    return self;
}

// clang-format on

// --- CODE GENERATION MARKER

@end

NS_ASSUME_NONNULL_END
