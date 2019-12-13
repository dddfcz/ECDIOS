//
//  ECVoIPSetManager.h
//  CCPiPhoneSDK
//
//  Created by ronglian on 15/1/26.
//  Copyright (c) 2015年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#else
#import <AppKit/AppKit.h>
#endif
#import "ECManagerBase.h"
#import "ECAudioConfig.h"
#import "NetworkStatistic.h"
#import "ECWaterMark.h"
#import "ECRecordMember.h"

typedef NS_ENUM(NSUInteger,ECSrtpCryptoType)  {
    ECSrtpCryptoType_AES_128_SHA1_80 = 1,
    ECSrtpCryptoType_AES_128_SHA1_32 = 2,
    ECSrtpCryptoType_AES_256_SHA1_80 = 3,
    ECSrtpCryptoType_AES_256_SHA1_32 = 4,
};

typedef NS_ENUM(NSUInteger, ECFilterType){
    ECFilterType_None= 0,
    ECFilterType_BeautyFaceFilter,
    ECFilterType_GrayFilter
};

typedef NS_ENUM (NSUInteger, ECRecordTypes){
    ECRecordType_flv = 1 << 1,
    ECRecordType_aac = 1 << 2,
    ECRecordType_h264 = 1 << 3,
    ECRecordType_mp4 = 1 << 4,
    ECRecordType_jpeg = 1 << 5
};

typedef NS_ENUM (NSUInteger, ECRecordResolutionIdx){
    ECRecordResolutionIdx_320,
    ECRecordResolutionIdx_480,
    ECRecordResolutionIdx_640,
    ECRecordResolutionIdx_960,
    ECRecordResolutionIdx_1280
};

typedef NS_ENUM (NSUInteger, ECRecordMode){
    ECRecordMode_Auto,
    ECRecordMode_Manual
};

@protocol ECVoIPSetManager<ECManagerBase>

#pragma mark - 基本设置函数

/**
 @brief 静音设置
 @param on NO:正常 YES:静音
 */
- (NSInteger)setMute:(BOOL)on;

/**
 @brief 获取当前静音状态
 @return NO:正常 YES:静音
 */
- (BOOL)getMuteStatus;

/**
 @brief 获取当前免提状态
 @return NO:关闭 YES:打开
 */
- (BOOL)getLoudsSpeakerStatus;

/**
 @brief 免提设置
 @param enable NO:关闭 YES:打开
 */
- (NSInteger)enableLoudsSpeaker:(BOOL)enable;

/**
 @brief 设置电话
 @param phoneNumber 电话号
 */
- (void)setSelfPhoneNumber:(NSString *)phoneNumber;

/**
 @brief 设置voip通话个人信息
 @param voipCallUserInfo VoipCallUserInfo对象
 */
- (void)setVoipCallUserInfo:(VoIPCallUserInfo *)voipCallUserInfo;

/**
 @brief 设置视频通话显示的view
 @param view 对方显示视图
 @param localView 本地显示视图
 */
#if TARGET_OS_IPHONE
- (NSInteger)setVideoView:(UIView*)view andLocalView:(UIView*)localView;
- (NSInteger)setVideoView:(UIView*)view andLocalView:(UIView*)localView remoteShareView:(UIView*)remoteShareView;
#elif TARGET_OS_MAC
- (NSInteger)setVideoView:(NSView*)view andLocalView:(NSView*)localView;
- (NSInteger)setVideoView:(NSView*)view andLocalView:(NSView*)localView remoteShareView:(NSView*)remoteShareView;
#endif

/**
 @brief 重新设置当前视频通话显示的view
 @param view 对方显示视图
 @param localView 本地显示视图
 @param callid 当前视频会话id
 */
#if TARGET_OS_IPHONE
- (NSInteger)resetVideoView:(UIView*)view andLocalView:(UIView*)localView ofCallId:(NSString*)callid;
#elif TARGET_OS_MAC
- (NSInteger)resetVideoView:(NSView*)view andLocalView:(NSView*)localView ofCallId:(NSString*)callid;
#endif


/**
 @brief 获取摄像设备信息
 @return 摄像设备信息数组
 */
- (NSArray*)getCameraInfo;

/**
 @brief 选择使用的摄像设备
 @param cameraIndex 设备index
 @param capabilityIndex 能力index
 @param fps 帧率
 @param rotate 旋转的角度
 @return  成功 0 失败 -1
 */
- (NSInteger)selectCamera:(NSInteger)cameraIndex capability:(NSInteger)capabilityIndex fps:(NSInteger)fps rotate:(ECRotate)rotate;

/**
 @brief 选择使用的摄像设备
 @param cameraIndex 设备index
 @param capabilityIndex 能力index
 @param fps 帧率
 @param rotate 旋转的角度
 @param isForce 是否强制启动本SDK调用的摄像头，默认使用NO
 @param scale 编码缩放，正实数。默认1.0，小于1.0缩小，大于1.0放大
 @return  成功 0 失败 -1
 */
- (NSInteger)selectCamera:(NSInteger)cameraIndex capability:(NSInteger)capabilityIndex fps:(NSInteger)fps rotate:(ECRotate)rotate force:(BOOL)isForce scale:(CGFloat)scale;

/**
 @brief 设置支持的编解码方式，默认全部都支持
 @param codec 编解码类型
 @param enabled NO:不支持 YES:支持
 */
-(void)setCodecEnabledWithCodec:(ECCodec)codec andEnabled:(BOOL)enabled;

/**
 @brief 获取编解码方式是否支持
 @param codec 编解码类型
 @return NO:不支持 YES:支持
 */
-(BOOL)getCondecEnabelWithCodec:(ECCodec)codec;

/**
 @brief 设置媒体流冗余。打开后通话减少丢包率，但是会增加流量
 @param AudioRed:音频开关,底层默认2。0关闭，1协商打开,2只有会议才协商
 */
- (void)setAudioCodecRed:(NSInteger)AudioRed;

/**
 @brief 获得媒体流冗余当前设置值。
 */
- (NSInteger)getAudioCodecRed;

/**
 @brief 是否开启H264硬编解码
 @param encode YES开启，NO关闭；默认开启
 @param decode YES开启，NO关闭；默认开启
 @return 是否成功 0:成功； 非0失败
 */
- (NSInteger)enableH264HardEncode:(BOOL)encode decode:(BOOL)decode;

/**
 @brief  设置客户端标示
 @param agent 客服账号
 */
- (void)setUserAgent:(NSString *)agent;

/**
 @brief 设置音频处理的开关,在呼叫前调用
 @param type  音频处理类型. enum AUDIO_TYPE { AUDIO_AGC, AUDIO_EC, AUDIO_NS };
 @param enabled YES：开启，NO：关闭；AGC默认关闭; EC和NS默认开启.
 @param mode: 各自对应的模式: AUDIO_AgcMode、AUDIO_EcMode、AUDIO_NsMode.
 @return  成功 0 失败 -1
 */
-(NSInteger)setAudioConfigEnabledWithType:(ECAudioType)type andEnabled:(BOOL)enabled andMode:(NSInteger)mode;

/**
 @brief 获取音频处理的开关
 @param type  音频处理类型. enum AUDIO_TYPE { AUDIO_AGC, AUDIO_EC, AUDIO_NS };
 @return  成功：音频属性结构 失败：nil
 */
-(ECAudioConfig*)getAudioConfigEnabelWithType:(ECAudioType)type;

/**
 @brief 设置视频通话码率
 @param bitrates  视频码流，kb/s，范围30-300
 */
-(void)setVideoBitRates:(NSInteger)bitrates;

/**
 @brief 统计通话质量
 @return  返回丢包率等通话质量信息对象
 */
-(CallStatisticsInfo*)getCallStatisticsWithCallid:(NSString*)callid andType:(CallType)type;

/**
 @brief 获取通话的网络流量信息
 @param   callid :  会话ID,会议类传入房间号
 @return  返回网络流量信息对象
 */
- (NetworkStatistic*)getNetworkStatisticWithCallId:(NSString*)callid;

/**
 @brief 通话过程中设置本端摄像头开启关闭，自己能看到对方，通话对方看不到自己。
 @param callid:会话ID
 @param on:是否开启
 @return 是否成功 0：成功； 非0失败
 */
- (NSInteger)setLocalCameraOfCallId:(NSString*)callid andEnable:(BOOL)enable;

/**
 @brief 设置美颜处理。支持通话中实时生效
 @param enable:是否开启
 @return 是否成功 0：成功； 非0失败
 */
- (NSInteger)enableBeautyFilter:(BOOL)enable EC_DEPRECATED_IOS(5.2.2, 5.4.2,"Use - setFilter:");

/**
 @brief 设置滤镜。支持通话中实时生效
 @param filterType:滤镜类型
 @return 是否成功 0：成功； 非0失败
 */
- (NSInteger)setFilter:(ECFilterType)filterType;

/**
 @brief 获取通话的ServerId，用于服务器录像
 @param callid 电话id
 @return ServerId
 */
-(NSString*)getServerIdFromCallId:(NSString*)callid;

/**
 @brief 设备采集原始音视频数据回调到上层
 @param isAudioEnable:上传音频
 @param isVideoEnable:上传视频
 @return 是否成功 0：成功； 非0失败
 */
- (NSInteger)setCaptureDataCallbackAudioEnabled:(BOOL)isAudioEnable videoEnable:(BOOL)isVideoEnable;

/**
 @brief 远程快照
 @param callid:当前呼叫的唯一标识.
 @param fileName:快照文件保存的全路径，含后缀名.jpg
 @return 是否成功 0：成功； 非0失败
 */
- (NSInteger)saveRemoteVideoSnapshot:(NSString*)callid fileName:(NSString*)fileName;

/**
 @brief 获取通话中的视频统计报告
 reportsJsonOut:  统计数据
 {
 "VideoSenderStatistics":[{"channelId":(通道id,uint32),"codecName":"(编码名称，string)","transmitBitrate":(码率，uint32),"width":(宽，uint32),"height":"(高，uint32)","frameRate":(帧率，uint32),"lossPercent":"(丢包率，单位%，uint32)","rttMs":(时延，单位毫秒，uint32)}]，
 "VideoReceiverStatistics":[{"channelId":(通道id,uint32),"codecName":"(编码名称，string)","transmitBitrate":(码率，uint32),"width":(宽，uint32),"height":"(高，uint32)","frameRate":(帧率，uint32)}]
 }
 */
- (NSString*)getStatsReports;

/**
 @brief 本地快照
 @param callid:当前呼叫的唯一标识.
 @param fileName:快照文件保存的全路径，含后缀名.jpg
 @return 是否成功 0：成功； 非0失败
 */
- (NSInteger)saveLocalVideoSnapshot:(NSString *)callid fileName:(NSString*)fileName;

- (NSInteger)startRecordMicrophone:(NSString*)fileName;
- (NSInteger)stopRecordMicrophone;

- (NSInteger)startRecordSendVoice:(NSString*)fileName;
- (NSInteger)stopRecordSendVoice;

- (NSInteger)startRecordPlayout:(NSString*)callid fileName:(NSString*)fileName;
- (NSInteger)stopRecordPlayout:(NSString*)callid;
/**
 @brief 设置重传模式
 @param audio:底层默认1。0关闭，1协商打开，2强制打开
 @param video:底层默认1。0关闭，1协商打开，2强制打开
 @return 是否成功 0：成功； 非0失败
 */
-(void)setCodecNackAudio:(NSInteger)audio video:(NSInteger)video;

/**
 @brief 设置SRTP加密属性
 @param enable:是否开启
 @param type:加密类型
 */
-(void)setSrtpEnabled:(BOOL)enable cryptoType:(ECSrtpCryptoType)type;

/**
 @brief P2P设置
 @param isNatP2P:是否开启
 @return 是否成功 0：成功； 非0失败
 */
- (NSInteger)setNatTraversal:(BOOL)isNatP2P;

/**
 @brief 获取P2P设置
 @return 是否开启 YES:开启； NO:关闭
 */
- (BOOL)getNatTraversal;

/**
 @brief 邀请三方加入
 @param member 第三方账号
 @param callId 会话ID
 @param displayName 显号
 @param completion 执行结果回调block
 */
- (void)inviteThreePart:(NSString*)member join:(NSString*)callId dispalyName:(NSString*)displayName completion:(void(^)(ECError *error))completion;

/**
 @brief 开启服务器录像
 @param callid 会话ID
 @param fileName 录像文件名称
 @param filePath 录像服务器地址
 @param resolution 录像分辨率 720p或1080p
 @param source 录制源，0录制双方、1主叫、2被叫
 @param isMix 是否混屏
 @param url 录制回调URL
 @param completion 执行结果回调block
 */
- (void)startServerRecord:(NSString*)callid fileName:(NSString*)fileName filePath:(NSString*)filePath resolution:(NSString*)resolution source:(NSInteger)source isMixScreen:(BOOL)isMix callBackUrl:(NSString*)url completion:(void(^)(ECError *error))completion;

/**
 @brief 关闭启服务器录像
 @param callid 会话ID
 @param completion 执行结果回调block
 */
- (void)stopServerRecord:(NSString*)callid completion:(void(^)(ECError *error))completion;

/**
 @brief 请求第三方视频
 @param displayView 视频显示view
 @param completion 执行结果回调block
 */
#if TARGET_OS_IPHONE
- (void)requestCurrentThreePartMemberVideo:(UIView*)displayView completion:(void(^)(ECError *error))completion;
#elif TARGET_OS_MAC
- (void)requestCurrentThreePartMemberVideo:(NSView*)displayView completion:(void(^)(ECError *error))completion;
#endif


/**
 @brief 取消第三方视频
 @param completion 执行结果回调block
 */
- (void)cancelCurrentThreePartMemberVideo:(void(^)(ECError *error))completion;

/**
 @brief 转接第三方
 @param callid 会话ID
 @param member 第三方账号
 @param displayNumber 显示号码
 @param completion 执行结果回调block
 */
- (void)transferCall:(NSString*)callid toMember:(NSString*)member displayNumber:(NSString*)displayNumber completion:(void(^)(ECError *error))completion;

/**
 @brief 强拆第三方
 @param callid 会话ID
 @param completion 执行结果回调block
 */
- (void)forceThreePartRelease:(NSString*)callid completion:(void(^)(ECError *error))completion;


/**
 @brief

 @param mode 模式 默认0 底层媒体库RTCP；1 INFO模式
 @return 是否成功 0：成功； 非0失败
 */
-(NSInteger)setRequestKeyFrameMode:(NSInteger)mode;


/**
 @brief 设置未收到对方媒体超时上报周期。

 @param secondTime 周期，单位秒。底层默认20秒
 */
- (void)setMediaPacketTimeout:(NSInteger)secondTime;


/**
 @brief 保存与设置根据网络类型不同的心跳包周期

 @param time 超时时间。 单位秒
 @param type networktype    : 网络类型
 */
- (void)setKeepAliveTimeout:(NSInteger)time networkType:(ECNetworkType)type;


/**
 @berief

 @param waterMark 设置视频滤镜。支持通话中实时生效
 */
- (void)setVideoWatermark:(ECWaterMark *)waterMark;

#pragma mark -- 5.4.3.4
/**
 @brief 网络抓包

 @param callid 点对点通话id
 @param mediaType 媒体类型
 @param fileName 抓包写入的文件路径
 @param direction 方向 0下行，1上行
 @return 是否成功 0：成功； 非0失败
 */
-  (int)startRtpDump:(NSString *)callid mediaType:(ECMediaType)mediaType fileName:(NSString *)fileName direction:(NSInteger)direction;


/**
 @brief 停止网络抓包

 @param callid 通话id
 @param mediaType 媒体类型
 @param direction 方向 0下行，1上行
 @return 是否成功 0：成功； 非0失败
 */
- (int)stopRtpDump:(NSString *)callid mediaType:(ECMediaType)mediaType direction:(NSInteger)direction;

/**
 @beief 是否打开抗拒马赛克功能

 @param bShieldMosaic YES 打开抗马赛克 NO 关闭抗马赛克 默认关闭
 @return 0 成功
 */
- (int)setShieldMosaic:(BOOL)bShieldMosaic;

#pragma mark -- 5.4.3.4

/**
 @brief 设置发送端和接受端 rtp 拓展头audio level开启状态

 @param sendStatus ture 开启 false 关闭
 @param recvStatus ture 开启 false 关闭
 @return 0：成功   非0：失败
 */
- (int)setAudiolevelStatus:(BOOL)sendStatus receive:(BOOL)recvStatus;

- (NSString *)getUserData:(NSString *)callId;

#pragma mark -- 5.4.11.2
/**
 @brief
 
 @param callId 会话id
 @param type 录制类型
 @param path 录像文件输出路径输出格式: aaa/bbb/
 @param fileName 录像文件名，不带扩展名
 @param idx 布局 -1 自动 0 首成员个大屏显示，其他成员小屏显示，首个成员即 members 参数中第一个成员
 @param idx 分辩率索引，分辨率与码率有固定值，根据不同索引，设置这些固定值
 @param mode 混屏切换模式: auto:自动布局 manual:手动布局
 @param members 所控制的会议成员
 @param url 直播推流地址，将录像直播到该地址
 */
- (void)startRecordP2P:(NSString *)callId recordType:(ECRecordTypes)type outputPath:(NSString *)path outputName:(NSString *)fileName layoutIdx:(NSString *)layoutIdx resolutionIdx:(ECRecordResolutionIdx)resolutionIdx recordMode:(ECRecordMode)mode members:(NSArray<ECRecordMember *> *)members rtmpPushUrl:(NSString *)url completion:(void(^)(ECError *error, NSArray *sessionIds))completion;

/**
 @brief 停止录制
 
 @param callId
 @param sessionId 会话ID
 */
- (void)stopRecordP2P:(NSString *)callId sessionId:(NSString *)sessionId completion:(void(^)(ECError* error, NSArray *recordData))completion;

/**
 @brief 录制成员切换
 
 @param callId
 @param sessionId 会议ID
 @param idx 布局
 @param mode 混屏切换模式
 @param members 所控制的会议成员
 */
- (void)recordP2pSwitchMember:(NSString *)callId sessionId:(NSString *)sessionId layoutIdx:(NSString *)idx recordModel:(ECRecordMode)mode members:(NSArray<ECRecordMember *> *)members completion:(void(^)(ECError *error))completion;


/**
 @brief 获取会议录制文件列表
 
 @param callId 通话id
 @param sessionId 会话ID
 */
- (void)recordP2pGetFileList:(NSString *)callId sessionId:(NSString *)sessionId completion:(void(^)(ECError* error, NSArray *recordData))completion;

/**
 @brief 删除会议录制文件
 
 @param callId
 @param sessionId
 @param filename 录像文件名， 需要带扩展名
 @param prefix 文件路径匹配值， 如果带该参数，只有录像存放路径中，有prefix的值，才删除，否则，不删除，为空时，删除会议下所有filename的文件
 */
- (void)recordP2pDelete:(NSString *)callId sessionId:(NSString *)sessionId fileName:(NSString *)filename prefix:(NSString *)prefix completion:(void(^)(ECError *error))completion;

/**
 @brief 设置墨镜开关
 
 @param enabled NO:关 YES:开
 */
- (int)setReportEngineEnable:(BOOL)enable;
@end
