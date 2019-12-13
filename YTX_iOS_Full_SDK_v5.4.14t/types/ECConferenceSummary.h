//
//  ECConferenceSummary.h
//  CCPiPhoneSDK
//
//  Created by xt on 2019/1/9.
//  Copyright © 2019 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ECConferenceSummary : NSObject

/**
 @brief 会议id
 */
@property (nonatomic, copy) NSString *confId;

/**
 @brief  纪要唯一ID
 */
@property (nonatomic, copy) NSString *confSummaryId;

/**
 @brief member id
 */
@property (nonatomic, copy) NSString *memberId;

@property (nonatomic, assign) int idType;

/**
 @brief 纪要内容
 */
@property (nonatomic, copy) NSString *summaryText;

/**
 @brief 开始时间
 */
@property (nonatomic, copy) NSString *startTimestamp;

/**
 @brief 结束时间
 */
@property (nonatomic, copy) NSString *endTimestamp;

@end

NS_ASSUME_NONNULL_END
