//
//  ECEntityConferenceInfo.h
//  CCPiPhoneSDK
//
//  Created by xt on 2019/1/15.
//  Copyright © 2019 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECConferenceInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface ECEntityConferenceInfo : NSObject

@property (nonatomic, copy) NSString *memberId;
@property (nonatomic, assign) int idType;
@property (nonatomic, copy) NSString *confRoomName;
@property (nonatomic, assign) NSInteger confRoomType;
@property (nonatomic, copy) NSString *city;
@property (nonatomic, copy) NSString *position;
@property (nonatomic, copy) NSString *deviceUserId;
@property (nonatomic, copy) NSString *photoUrl;
@property (nonatomic, copy) NSString *companyId;

/**
 @brief 容纳人数，实体会议室的描述信息
 */
@property (nonatomic, assign) NSInteger capacity;

@end

NS_ASSUME_NONNULL_END
