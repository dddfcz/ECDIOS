//
//  ECConferenceInfo.h
//  CCPiPhoneSDK
//
//  Created by jiazy on 2017/2/17.
//  Copyright © 2017年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECConferenceMemberInfo.h"

@class ECEntityConferenceInfo;

typedef NS_ENUM(NSInteger,ECConferenceType) {
        
    /** 临时会议 */
    ECConferenceType_Temporary = 0,
    
    /** 永久会议 */
    ECConferenceType_Permanent = 1,
    
    /** 预约会议 */
    ECConferenceType_Subscribe = 2,
};

typedef NS_ENUM(NSInteger,ECConferenceVoiceMode) {
    
    /** 只有背景音 */
    ECConferenceVoiceMode_OnlyBackground = 0,
    
    /** 背景音提示音 */
    ECConferenceVoiceMode_All = 1,
    
    /** 无背景音 */
    ECConferenceVoiceMode_None = 2,
    
    /** 只有提示音 */
    ECConferenceVoiceMode_OnlyPrompt = 3
};

typedef NS_ENUM(NSInteger,ECConferenceMediaType) {
    
    /** 纯落地电话会议 */
    ECConferenceMediaType_OnlyPhone = 0,
    
    /** 多路视频流 */
    ECConferenceMediaType_MultiVideo = 1,
    
    /** 视频混屏 */
    ECConferenceMediaType_MixVideo = 2,
    
    /** 多路+混屏 */
        ECConferenceMediaType_All = 3,
        
        /** 实时对讲 */
        ECConferenceMediaType_RealTimeIntercom = 4,

    /*有序发言，限制同时发布语音的人数*/
    ECConferenceMediaType_limitVoice = 5
};


typedef NS_ENUM(NSInteger,ECConferenceUserState) {
    
    /** 共享视频 */
    UserStateCameraSharing = 0x000004,
    
    /** 共享语音 */
    UserStateAllowSpeak = 0x000040
};

typedef NS_ENUM(NSInteger,ECConferenceState) {
    
    /** 是否开始过 */
    ConferenceStatePersonJoined = 0x000001,
    
    /** 会议加锁状态 */
    ConferenceStateLocked = 0x000002,
    
    /** 白板加锁状态 */
    ConferenceStateShareLocked = 0x000004,
    
    /** 标注加锁状态 */
    ConferenceStateMarkLocked = 0x000008,
    
    /** 白板共享中 */
    ConferenceStateShareWhiteboard = 0x0010,

    /**正在共享屏幕*/
    ConferenceStateShareScreen = 0x0020,
    
    /**正在录制*/
    ConferenceStateRecording = 0x0040,
    
    /**正在直播*/
    ConferenceStateLiving = 0x0080,
    
    /**已经锁定发言（此时禁止 RoleAttendeeLimit = 10 成员发布语音）*/
    ConferenceStateLockPublishVoice = 0x0100
};

typedef NS_ENUM(NSInteger,ECConferenceContentType) {
    
    /** 普通会议事件，音视频会议事件 */
    ECConference_ContentTypeCommon = 0,
    
    /** 企业云会议室中，允许创建音视频会议事件*/
    ECConference_ContentTypeEntity,

    /**  */
    ECConference_ContentTypeEnterpriseCloud,

    /** 企业实体会议室中，允许创建 音视频会议事件 和 实体会议事件。 允许 音视频会议 与 实体会议 的时间段重复 */
    ECConference_ContentTypeEnterpriseEntity
};

/**
 *  会议信息
 */
@interface ECConferenceInfo : NSObject

/**
 @brief 会议ID
 */
@property (nonatomic, copy) NSString* conferenceId;

/**
 @brief 会议室ID
 */
@property (nonatomic, copy) NSString* conferenceRoomId;

/**
 @brief 创建者
 */
@property (nonatomic, strong) ECAccountInfo* creator;

/**
 @brief 会议名称
 */
@property (nonatomic, copy) NSString* confName;

/**
 @brief 创建者密码
 */
@property (nonatomic, copy) NSString* ownerPassword;

/**
 @brief 普通成员密码
 */
@property (nonatomic, copy) NSString* password;

/**
 @brief 会议类型
 */
@property (nonatomic, assign) ECConferenceType confType;

/**
 @brief 媒体类型
 */
@property (nonatomic, assign) ECConferenceMediaType mediaType;

/**
 @brief 最大成员数
 */
@property (nonatomic, assign) NSUInteger maxMember;

/**
 @brief 背景音类型
 */
@property (nonatomic, assign) ECConferenceVoiceMode voiceMode;

/**
 @brief 主持人离开会议后，会议是否自动结束 (0:否，1:是)
 */
@property (nonatomic, assign) NSUInteger autoClose;

/**
 @brief 指定会议主持人ID
 */
@property (nonatomic, assign) NSString *moderator;

/**
 @brief 预约的会议中使用这个字段，会议开始时间
        格式:yyyy-MM-dd HH:mm:ss
 */
@property (nonatomic, copy) NSString *startTime;

/**
 @brief 预约会议开始时间
 */
@property (nonatomic, copy) NSString* reserveStartTime;

/**
 @brief 会议开始时间
 */
@property (nonatomic, copy) NSString* liveStartTime;

/**
 @brief 会议结束时间
 */
@property (nonatomic, copy) NSString* endTime;

/**
 @brief 预约的会议中使用这个字段，预约的参会成员
 */
@property (nonatomic, copy) NSArray *members;


/**
 @brief 预约的会议中使用这个字段，预约的参会成员个数
 */
@property (nonatomic, assign) NSUInteger membersCount;

/**
 @brief 预约的会议中使用这个字段，会议持续时间
        单位:分钟 默认值60
 */
@property (nonatomic, assign) NSUInteger duration;

/**
 @brief 到时间之后是否发送入会邀请
        (对于应用账号发送邀请通知，对于手机号发起邀请呼叫)
        0:否，1:是 默认值 1
 */
@property (nonatomic, assign) NSUInteger sendInvitation;

/**
 @brief 预约的会议中使用这个字段，会议开始前多久发送提醒通知
        单位:分钟 默认值10
 */
@property (nonatomic, assign) NSUInteger remindBeforeStart;

/**
 @brief 预约的会议中使用这个字段，会议结束前多久发送提醒通知
        单位:分钟 默认值10
 */
@property (nonatomic, assign) NSUInteger remindBeforeEnd;

/**
 @brief 是否启用预约功能 0:不启用，1：启用
 启用预约功能时
 在预约结束时间之后（startTime+duration），才会自动结束
 在预约结束时间之前，用户可随时加入并使用会议，接口不做任何限制，且confType和autoClose参数不起作用
 */
@property (nonatomic, assign) NSUInteger reserveEnable;

/**
 @brief 议题json
 */
@property (nonatomic, copy) NSString* confTopic;

/**
 @brief 会议摘要数量
 */
@property (nonatomic, assign) NSUInteger confAbstractCount;

/**
 @brief 文件库文件数量
 */
@property (nonatomic, assign) NSUInteger confFileCount;

/**
 @brief 成员入会时状态(是否打开语音或视频)
 */
@property (nonatomic, assign) NSUInteger joinState;

/**
 @brief 成员调用加入会议后后台返回的处理后的状态(是否打开语音或视频)
 */
@property (nonatomic, assign) NSInteger joinStateAfterJoin;

/**
 @brief 白板信息
 */
@property (nonatomic, copy) NSString* wbInfo;

/**
 @brief 是否允许电话参会功能，启用后，此会议，才允许外呼成员手机号 0不启用；1启用；默认1，表示启用
 */
@property (nonatomic, assign) int allowCallOut;

/**
 @brief 1个人，2企业
 */
@property (nonatomic, assign) int confRoomType;

/**
 @brief 电话
 */
@property (nonatomic, copy) NSArray *telNum;

/**
 @brief im群组ID
 */
@property (nonatomic, copy) NSString *chatGroupId;

/**
 @brief 是否启用会中IM
 */
@property (nonatomic, assign) BOOL chatInConf;

/**
 @brief 预留
 */
@property (nonatomic, copy) NSString* appData;

@property (nonatomic, copy) NSString* createTime;

@property (nonatomic, copy) NSString* updateTime;

@property (nonatomic, assign) NSInteger state;

/**
 @brief 标识最大发言人数
 */
@property (nonatomic, assign) NSInteger maxPublishVoiceMember;

/**
 @brief 创建的会议版本，用于 PolyComMCU 对接时使用
 */
@property (nonatomic, assign) NSInteger version;

/**
 @brief 会议事件类型
 */
@property (nonatomic, assign) ECConferenceContentType contentType;

/**
 @brief 实体会议信息
 */
@property (nonatomic, strong) ECEntityConferenceInfo *entryConfInfo;

/**
 @brief 创建会议时，如果超过并发数限制，会返回 suggestMaxMember 字段，表示当前可用的最大并发用户数
 */
@property (nonatomic, assign) NSInteger suggestMaxMember;

@end
