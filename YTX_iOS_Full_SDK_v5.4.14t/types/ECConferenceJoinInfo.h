//
//  ECConferenceJoinInfo.h
//  CCPiPhoneSDK
//
//  Created by jiazy on 2017/2/17.
//  Copyright © 2017年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECConferenceMemberInfo.h"
#import "ECConferenceInfo.h"
/**
 *  会议加入信息
 */
@interface ECConferenceJoinInfo : NSObject

/**
 @brief 会议ID
 */
@property (nonatomic, copy) NSString *conferenceId;

/**
 @brief 会议密码
 */
@property (nonatomic, copy) NSString *password;

/**
 @brief 用户昵称
 */
@property (nonatomic, copy) NSString *userName;

/**
 @brief 邀请者
 */
@property (nonatomic, copy) NSString *inviter;

/**
 @brief 媒体类型
 */
@property (nonatomic, assign) ECConferenceMediaType mediaType;

/**
 @brief 账号类型
 */
@property (nonatomic, assign) ECAccountType inviterType;

/**
 @brief 角色类型
 */
@property (nonatomic, assign) NSInteger roleId;

/**
 @brief 预留
 */
@property (nonatomic, copy) NSString *appData;

/**
 @brief 手机号
 */
@property (nonatomic, copy) NSString *phoneNumber;

/**
 @brief 入会状态
 */
@property (nonatomic, assign) NSInteger joinState;

/**
 @brief 入会终端类型 （操作系统类型） iPhone Android Windows Mac Web
 */
@property (nonatomic, copy) NSString *terminalUA;

/**
 @brief 当前遥控硬件的成员
 */
@property (nonatomic, copy) NSString *deviceUserId;

/**
 @brief 硬件端入会时传此参数， 表示遥控者的 UserId
 */
@property (nonatomic, copy) NSString *masterUserId;

@end
