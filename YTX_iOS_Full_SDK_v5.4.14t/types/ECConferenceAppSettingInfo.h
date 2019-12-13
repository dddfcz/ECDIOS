//
//  ECConferenceAppSettingInfo.h
//  CCPiPhoneSDK
//
//  Created by 王文龙 on 2017/7/11.
//  Copyright © 2017年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ECConferenceAppSettingInfo : NSObject
/**
 @brief 会议呼入电话号码，列表。
 */
@property (nonatomic, copy) NSArray *telNum;

/**
 @brief 会议最大成员数。最大不能超过应用中设置的最大数值。
 */
@property (nonatomic, assign) NSInteger maxMember;

/**
 @brief 会议最小成员数。最小不能低于应用中设置的最小数值。
 */
@property (nonatomic, assign) NSInteger minMember;

/**
 @brief 是否启用多终端登录功能，启用后成员 MemberId 字段会有变化  0表示关闭，1表示启用
 */
@property (nonatomic, assign) NSInteger multiTerminal;

/**
 @brief 提供媒体功能的厂商 1：云通讯 2：avaya
 */
@property (nonatomic, assign) NSInteger mediaVendor;

/**
 @brief 应用ID
 */
@property (nonatomic, copy) NSString * appId;

/**
 @brief appData
 */
@property (nonatomic, copy) NSString * appData;

/**
 @brief 会议web服务器的base url
 */
@property (nonatomic, copy) NSString * confBaseUrl;

/**
 @brief 会议通知的回调url。当会议中产生了通知时，调用这个url进行通知发送（通知内容统一定义）
 */
@property (nonatomic, copy) NSString * notifyUrl;

/**
 @brief 当用户通过主动呼叫会议电话号码加入会议时，或者
 当平台会议外呼到用户号码（落地,voip），邀请加入会议时，进行验证IVR流程的调用url
 如果不提供，则使用平台默认的验证方式（主动加入使用会议ID+密码的方式验证，邀请的不验证）
 默认为空
 */
@property (nonatomic, copy) NSString * verifyUrl;

/**
 @brief 创建时间
 */
@property (nonatomic, copy) NSString * createTime;

/**
 @brief 更新时间
 */
@property (nonatomic, copy) NSString * updateTime;

/**
 @brief
 */
@property (nonatomic, assign) NSInteger teleCallRetry;

/**
 @brief
 */
@property (nonatomic, assign) NSInteger retryTime;

@end
