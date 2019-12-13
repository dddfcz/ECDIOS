//
//  ECConferenceMemberInfo.h
//  CCPiPhoneSDK
//
//  Created by jiazy on 2017/2/17.
//  Copyright © 2017年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECEnumDefs.h"

typedef NS_ENUM(NSUInteger,ECConferenceMemberState) {
    
    /** 不在线 */
    ECConferenceMemberState_Offline = 0x00000000,
    
    /** 在线 */
    ECConferenceMemberState_Online = 0x00000001,
    
    /** 正在说话 */
    ECConferenceMemberState_Speaking = 0x00000002,
    
    /** 有摄像头视频 */
    ECConferenceMemberState_Video = 0x00000004,
    
    /** 共享了屏幕 */
    ECConferenceMemberState_Screen = 0x00000008,
    
    /** 共享了白板 */
    ECConferenceMemberState_ShareWhite = 0x00000010,
    
    /** 可讲，非静音状态 */
    ECConferenceMemberState_NoMute = 0x00000040,
    
    /** 可听 */
    ECConferenceMemberState_Listen = 0x00000080,
    
    /** 媒体在线，用户sip呼叫接通时，此位置1 */
    ECConferenceMemberState_MediaOnline = 0x00000100,
    
    /** 用户拒绝邀请，此位置1 */
    ECConferenceMemberState_Rejectinvite = 0x00000200,
    
    /** 正在呼叫中 */
    ECConferenceMemberState_BeCalling = 0x00000400,
    
    /** 已挂断 */
    ECConferenceMemberState_Hangup = 0x00000800,
    
    /*会议受限成员，置1表示 主持点名申请将其变更为发言人*/
    ECConferenceMemberState_ByModerator = 0x00010000,
    
    /*会议受限成员，置1表示 自己举手申请变更为发言人*/
    ECConferenceMemberState_BySelf = 0x00020000
    

};

typedef NS_ENUM(NSUInteger,ECAccountType) {
    
    /** 落地电话 */
    ECAccountType_PhoneNumber = 1,
    
    /** 应用账号 */
    ECAccountType_AppNumber = 2,
};

#pragma mark -
#pragma mark 账号信息
/**
 *  账号信息
 */
@interface ECAccountInfo : NSObject

/**
 @brief 账号ID
 */
@property (nonatomic, copy) NSString* accountId;

/**
 @brief 账号类型
 */
@property (nonatomic, assign) ECAccountType accountType;

/**
 @brief 多终端登录时的设备类型
 */
@property (nonatomic, assign) ECDeviceType deviceType;

/**
 @brief 昵称
 */
@property (nonatomic, copy) NSString* userName;

/**
 @brief 角色ID
 */
@property (nonatomic, assign) NSInteger roleId;

/**
 @brief 手机号
 */
@property (nonatomic, copy) NSString* phoneNumber;

/**
 @brief 拒绝错误码
 */
@property (nonatomic, copy) NSString* inviteResult;

/**
 @brief 版本，7三方加入
 */
@property (nonatomic, assign) NSInteger version;


/**
 @berife  ssrc信息
 */
@property (nonatomic, copy) NSString *videoSsrc;


- (void)setFullMemberId:(NSString *)memberId;
@end


#pragma mark -
#pragma mark 会议成员信息
/**
 *  会议成员信息
 */
@interface ECConferenceMemberInfo : NSObject

/**
 @brief 成员账号
 */
@property (nonatomic, strong) ECAccountInfo* account;

/**
 @brief 成员状态
 */
@property (nonatomic, assign) ECConferenceMemberState state;

@property (nonatomic, copy) NSString* joinTime;

@property (nonatomic, copy) NSString* leaveTime;

@property (nonatomic, copy) NSString* updateTime;

/**
 @brief 预留
 */
@property (nonatomic, copy) NSString* appData;

/**
 @brief 当前遥控硬件的成员
 */
@property (nonatomic, copy) NSString *deviceUserId;

/**
 @brief 硬件端入会时传此参数， 表示遥控者的 UserId
 */
@property (nonatomic, copy) NSString *masterUserId;

@end
