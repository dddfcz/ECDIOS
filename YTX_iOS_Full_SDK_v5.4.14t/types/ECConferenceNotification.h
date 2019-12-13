//
//  ECConferenceNotification.h
//  CCPiPhoneSDK
//
//  Created by jiazy on 2017/2/21.
//  Copyright © 2017年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECConferenceMemberInfo.h"
#import "ECConferenceManager.h"

typedef NS_ENUM(NSUInteger, ECConferenceNotificationType) {
    
    /** 会议删除 */
    ECConferenceNotificationType_Delete = 1,
    
    /** 成员加入 */
    ECConferenceNotificationType_Join = 2,
    
    /** 成员退出 */
    ECConferenceNotificationType_Quit = 3,
    
    /** 成员被踢出 */
    ECConferenceNotificationType_KickOut = 4,
    
    /** 成员信息更新 */
    ECConferenceNotificationType_MemberInfo = 5,
    
    /** 会议邀请 */
    ECConferenceNotificationType_Invite = 6,
    
    /** 会议邀请 */
    ECConferenceNotificationType_InviteResult = 7,
    
    /** 其他端接听取消会议邀请 */
    ECConferenceNotificationType_CancelInvite = 12,
    
    /** 会议信息更新 */
    ECConferenceNotificationType_Update = 17,
    
    /** 透传信息 */
    ECConferenceNotificationType_cmd = 19,
    
    /** 媒体被控制 */
    ECConferenceNotificationType_MediaControl = 22,
    
    /** 会议预约 */
    ECConferenceNotificationType_Subscribe = 24,
    
    /** 会议即将开始 */
    ECConferenceNotificationType_Near = 25,
    
    /** 会议结束前提醒通知 */
    ECConferenceNotificationType_RemindBeforeEnd = 26,
    
    /** 用户推荐通知 */
    ECConferenceNotificationType_Recommend = 30,
    
    /** 应用系统通知 */
    ECConferenceNotificationType_AppSystem = 31,
};

typedef NS_ENUM(NSInteger, ECConferenceDeleteType) {
    
    KControlDelConfByUser = 60, // 用户主动解散会议
    KControlDelConfByIdleConf = 61, // 会议空闲， 解散
    KControlDelConfByExceedLimit = 62, // 会议超出最大时长限制， 解散
    KControlDelConfByConflictInConfRoomError = 63, // 会议室繁忙， 内部异常 导致 无法延时
    KControlDelConfByConflictInConfRoomPrivate = 64, // 会议室繁忙， 有会议占用会议室， 必须解散冲突的预约会议 （私人会议室）
    KControlDelConfByConflictInConfRoomOrgPub = 65, // 会议室繁忙， 有预约会议占用会议室，无法延长当前会议时长 （企业会议室）
    
};

#pragma mark -
#pragma mark 会议通知基类
/**
 *  会议通知基类
 */
@interface ECConferenceNotification : NSObject

/**
 @brief 通知类型
 */
@property (nonatomic, assign) ECConferenceNotificationType type;

/**
 @brief 会议ID
 */
@property (nonatomic, copy) NSString *conferenceId;

/**
 @brief 发送时间／／2017-09-16 15:01:42
 */
@property (nonatomic, copy) NSString *sendTime;

/**
 @brief 会议开始时间／／2017-09-16 15:01:42
 */
@property (nonatomic, copy) NSString *startTime;

/**
 @brief conference 类型
 */
@property (nonatomic, assign) ECConferenceContentType contentType;

@end


#pragma mark -
#pragma mark 会议删除通知
/**
 *  会议删除通知
 */
@interface ECConferenceDeleteNotification : ECConferenceNotification

/**
 @brief 会议名称
 */
@property (nonatomic, copy) NSString* confName;


/**
 @brief 会议状态
 */
@property (nonatomic, assign) NSInteger state;

/**
 @brief 删除原因
 */
@property (nonatomic, assign) ECConferenceDeleteType deleteType;

/**
 @brief 实体会议信息
 */
@property (nonatomic, strong) ECEntityConferenceInfo *entryConfInfo;

@end

#pragma mark -
#pragma mark 会议加入通知
/**
 *  会议加入通知
 */
@interface ECConferenceJoinNotification : ECConferenceNotification

/**
 @brief 加入成员
 */
@property (nonatomic, strong) ECAccountInfo* member;

/**
 @brief 邀请者
 */
@property (nonatomic, strong) ECAccountInfo* inviter;

/**
 @brief 邀请成员
 */
@property (nonatomic, strong) NSArray* members;

@end


#pragma mark -
#pragma mark 会议退出通知
/**
 *  会议退出通知
 */
@interface ECConferenceQuitNotification : ECConferenceNotification
/**
 @brief 退出成员
 */
@property (nonatomic, strong) ECAccountInfo* member;

/**
 @brief 会议是否开始过
 */
@property (nonatomic, assign) NSInteger state;
@end


#pragma mark -
#pragma mark 成员被踢通知
/**
 *  成员被踢
 */
@interface ECConferenceKickOutNotification : ECConferenceNotification

/**
 @brief 踢人者
 */
@property (nonatomic, strong) ECAccountInfo* member;

/**
 @brief 被踢成员 ECAccountInfo
 */
@property (nonatomic, strong) NSArray *kickedMembers;

@end

#pragma mark -
#pragma mark 成员更新通知
/**
 *  成员更新通知
 */
@interface ECConferenceMemberInfoNotification : ECConferenceNotification

/**
 @brief 更新类型
 */
@property (nonatomic, assign) ECControlMediaAction action;

/**
 @brief 成员信息 ECConferenceMemberInfo
 */
@property (nonatomic, strong) NSArray *members;

@end

#pragma mark -
#pragma mark 邀请加入通知
/**
 *  邀请加入通知
 */
@interface ECConferenceInviteNotification : ECConferenceNotification

/**
 @brief 邀请者
 */
@property (nonatomic, strong) ECAccountInfo* inviter;

/**
 @brief 创建者
 */
@property (nonatomic, strong) ECAccountInfo* creator;

/**
 @brief 媒体类型
 */
@property (nonatomic, assign) ECConferenceMediaType mediaType;

/**
 @brief 会议名称
 */
@property (nonatomic, copy) NSString* confName;

/**
 @brief 会议密码
 */
@property (nonatomic, copy) NSString* password;

/**
 @brief 会议开始时间
 */
@property (nonatomic, copy) NSString* inviteTime;

/**
 @brief 邀请通知的唯一标识
 */
@property (nonatomic, copy) NSString* invitationId;

/**
 @brief 预留字段
 */
@property (nonatomic, copy) NSString* appData;

@property (nonatomic, assign) NSInteger callImmediately;

/**
 @brief 实体会议信息
 */
@property (nonatomic, strong) ECEntityConferenceInfo *entryConfInfo;

@end

#pragma mark -
#pragma mark 邀请加入结果通知
/**
 *  邀请加入结果通知
 */
@interface ECConferenceInviteResultNotification : ECConferenceNotification

/**
 @brief 被邀请者
 */
@property (nonatomic, strong) ECAccountInfo* invitee;

/**
 @brief 邀请结果
 */
@property (nonatomic, copy) NSString* cause;

/**
 @brief 预留字段
 */
@property (nonatomic, copy) NSString* appData;

@end

#pragma mark -
#pragma mark 预约会议通知
/**
 *  邀请加入通知
 */
@interface ECConferenceSubscribeNotification : ECConferenceNotification

/**
 @brief 邀请者
 */
@property (nonatomic, strong) ECAccountInfo* inviter;

/**
 @brief 会议名称
 */
@property (nonatomic, copy) NSString* confName;

/**
 @brief 会议密码
 */
@property (nonatomic, copy) NSString* password;

/**
 @brief 会议持续时间
 */
@property (nonatomic, copy) NSString* duration;

/**
 @brief 预留字段
 */
@property (nonatomic, copy) NSString* appData;

@end

#pragma mark -
#pragma mark 预约会议通知
/**
 *  邀请加入通知
 */
@interface ECConferenceNearNotification : ECConferenceNotification

/**
 @brief 创建者
 */
@property (nonatomic, strong) ECAccountInfo* creator;

/**
 @brief 会议名称
 */
@property (nonatomic, copy) NSString* confName;

/**
 @brief 距离时间
 */
@property (nonatomic, assign) int remindBeforeStart;

/**
 @brief 会议持续时间
 */
@property (nonatomic, copy) NSString* duration;

/**
 @brief 预留字段
 */
@property (nonatomic, copy) NSString* appData;

/**
 @brief 容纳人数， 实体会议室的描述信息
 */
@property (nonatomic, assign) NSInteger capacity;

@end

#pragma mark -
#pragma mark 推荐用户通知
/**
 *  邀请加入通知
 */
@interface ECConferenceProfile : NSObject

/**
 @brief 名字
 */
@property (nonatomic, copy) NSString* NickName;

/**
 @brief 手机
 */
@property (nonatomic, copy) NSString* Mobile;

/**
 @brief id
 */
@property (nonatomic, copy) NSString* UserId;

/**
 @brief 邮箱
 */
@property (nonatomic, copy) NSString* Email;

/**
 @brief 头像
 */
@property (nonatomic, copy) NSString* PhotoUrl;

/**
 @brief 更新时间
 */
@property (nonatomic, copy) NSString* UpdatedAt;

/**
 @brief
 */
@property (nonatomic, assign) NSInteger FirstLogin;

/**
 @brief
 */
@property (nonatomic, assign) NSInteger Gender;

/**
 @brief
 */
@property (nonatomic, assign) NSInteger UserType;

/**
 @brief
 */
@property (nonatomic, copy) NSString* CompanyUserId;

@end
/**
 *  用户推荐通知
 */
@interface ECConferenceRecommendNotification : ECConferenceNotification

/**
 @brief 成员
 */
@property (nonatomic, copy) NSArray* Profiles;

/**
 @brief 内容
 */
@property (nonatomic, copy) NSString* Text;

/**
 @brief url
 */
@property (nonatomic, copy) NSString* Url;

/**
 @brief  类型
 */
@property (nonatomic, assign) NSInteger InnerType;
@end

/**
 *  app系统通知
 */
@interface ECConferenceAppSystemNotification : ECConferenceNotification

/**
 @brief 成员
 */
@property (nonatomic, copy) NSArray* Profiles;

/**
 @brief 内容
 */
@property (nonatomic, copy) NSString* Text;

/**
 @brief url
 */
@property (nonatomic, copy) NSString* Url;

/**
 @brief  类型
 */
@property (nonatomic, assign) NSInteger InnerType;

@end

#pragma mark -
#pragma mark 会议更新通知
/**
 *  会议更新通知
 */
@interface ECConferenceUpdateNotification : ECConferenceNotification
/**
 @brief 创建者
 */
@property (nonatomic, strong) ECAccountInfo* creator;

/**
 @brief 更新者
 */
@property (nonatomic, strong) ECAccountInfo* member;

/**
 @brief 会议名称
 */
@property (nonatomic, copy) NSString *confName;

/**
 @brief 更新类型
 */
@property (nonatomic, assign) NSInteger action;

/**
 @brief 会议状态
 */
@property (nonatomic, assign) NSInteger state;

/**
 @brief 议题信息
 */
@property (nonatomic, copy) NSString *confTopic;

/**
 @brief 白板信息
 */
@property (nonatomic, copy) NSString *wbInfo;

/**
 @brief 会议开始时间
 */
@property (nonatomic, copy) NSString *liveStartTime;

/**
 @brief 会议最大人数改变
 */
@property (nonatomic, assign) NSInteger maxMember;

/**
 @brief 预留字段
 */
@property (nonatomic, copy) NSString *appData;

/**
 @brief 实体会议信息
 */
@property (nonatomic, strong) ECEntityConferenceInfo *entryConfInfo;

@end

#pragma mark -
#pragma mark 媒体被操作通知
/**
 *  媒体被操作通知
 */
@interface ECConferenceMediaControlNotification : ECConferenceNotification
/**
 @brief 操作者
 */
@property (nonatomic, strong) ECAccountInfo* member;

/**
 @brief 操作类型
 */
@property (nonatomic, assign) ECControlMediaAction action;

@property (nonatomic, assign) NSInteger allMember;

@end
#pragma mark -
#pragma mark 透明数据发送通知
/**
 *  透明数据
 */
@interface ECConferenceCmdNotification : ECConferenceNotification

/**
 @brief 发送者
 */
@property (nonatomic, strong) ECAccountInfo* member;

/**
 @brief 数据
 */
@property (nonatomic, copy) NSString *cmdData;

@end
#pragma mark -
#pragma mark 其他端接听取消会议邀请通知
/**
 * 其他端接听取消会议邀请
 */
@interface ECConferenceCancelInviteNotification : ECConferenceNotification

/**
 @brief 成员
 */
@property (nonatomic, copy) NSArray *members;

@end


#pragma mark - 会议结束前提醒通知
/**
 *  会议删除通知
 */
@interface ECConferenceRemindBeforeEndNotification : ECConferenceNotification

/**
 必选 会议下一次可用结束时间 用于延长会议时间使用
 */
@property (nonatomic, copy) NSString *nextEndTime;

/**
 必选 是否启用预约功能
 */
@property (nonatomic, assign) NSInteger reserveEnable;

/**
 必选
 会议状态
 会议当前状态，具体定义参考以下链接中 state 字段描述
 获取会议信息
 */
@property (nonatomic, assign) NSInteger state;

/**
 必选 离会议结束还剩多长时间，单位：分钟
 */
@property (nonatomic, assign) NSInteger remindBeforeEnd;

/**
 可选 预约的会议中使用这个字段，会议持续时间，单位：分钟 默认值60
 */
@property (nonatomic, assign) NSInteger duration;

/**
 可选
 0：电话会议，1：多流视频，2：混屏视频，3：多流混屏的混合模式，4：实时对讲；
 默认值：1
 */
@property (nonatomic, assign) ECConferenceMediaType mediaType;

/**
 可选 会议名称
 */
@property (nonatomic, copy) NSString *confName;

/**
 可选 普通成员密码
 */
@property (nonatomic, copy) NSString *password;

@end
