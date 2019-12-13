//
//  ECConferenceAbstract.h
//  CCPiPhoneSDK
//
//  Created by 王文龙 on 2018/3/19.
//  Copyright © 2018年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECConferenceMemberInfo.h"

typedef NS_ENUM(NSUInteger,ECConfAbstractType) {
    
    /** 私有摘要，仅自己可见 */
    ECConfAbstractType_Private = 1,
    
    /** 公共摘要，所有人可见 */
    ECConfAbstractType_Public = 2,
};
@interface ECConferenceAbstract : NSObject

/**
 @brief 摘要ID
 */
@property (nonatomic, copy) NSString* abstractId;
/**
 @brief 摘要内容
 */
@property (nonatomic, copy) NSString* abstractData;
/**
 @brief 公开类型 1:私有摘要，仅自己可见；2:公共摘要，所有人可见
 */
@property (nonatomic, assign) ECConfAbstractType abstractType;

/**
 @brief 会议ID
 */
@property (nonatomic, copy) NSString* confId;
/**
 @brief 创建时间
 */
@property (nonatomic, copy) NSString* createTime;
/**
 @brief 更新时间
 */
@property (nonatomic, copy) NSString* updateTime;
/**
 @brief 创建者
 */
@property (nonatomic, strong) ECAccountInfo* member;

@end
