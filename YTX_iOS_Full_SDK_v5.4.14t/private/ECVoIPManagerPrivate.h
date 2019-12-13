//
//  ECVoIPManagerPrivate.h
//  CCPiPhoneSDK
//
//  Created by ronglian on 15/1/26.
//  Copyright (c) 2015年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol ECVoIPManagerPrivate<NSObject>

/**
 @brief 设置MTU。目前只是视频通道有效
 @param mtu mtu值。最大不能超过1500，默认1200
 @return 是否成功 0:成功； 非0失败
 */
- (NSInteger)setMTU:(NSInteger)mtu;

/**
 @brief 是否开启H264硬编解码
 @param encode YES开启，NO关闭；默认开启
 @param decode YES开启，NO关闭；默认开启
 @return 是否成功 0:成功； 非0失败
 */
- (NSInteger)enableH264HardEncode:(BOOL)encode decode:(BOOL)decode;

- (NSInteger)resetAudioDevice;

/**
 @brief 设置允许上层处理音视频数据
 @discussion 一旦设置，必须把数据传回底层，否则没有媒体数据
 @param isAudioEnable YES:允许上层处理； NO:不允许上层处理。默认NO
 @param isVideoEnable YES:允许上层处理； NO:不允许上层处理。默认NO
 @return 是否成功 0：成功； 非0失败
 */
- (NSInteger)setProcessDataAudioEnable:(BOOL)isAudioEnable videoEnable:(BOOL)isVideoEnable;

/**
 @brief 设置未收到对方媒体超时上报周期
 @param secondTime 周期，单位秒。默认20秒
 */
- (void)setMediaPacketTimeout:(NSInteger)secondTime;

/**
 @brief 设置媒体通道保活包间隔周期
 @param audioInterval 音频通道间隔，默认8秒
 @param videoInterval 视频通道间隔，默认8秒
 @return 是否成功 0成功； 非0失败
 */
- (NSInteger)setRtpKeepaliveInterval:(NSInteger)audioInterval videoInterval:(NSInteger)videoInterval;

/**
 @brief 设置音频Red模式
 @param redMode 0关闭，1协商打开,2只有会议才协商;默认2
 @return 是否成功 0成功； 非0失败
 */
- (NSInteger)setAudioCodecRed:(NSInteger)redMode;

/**
 @brief 设置音频Red模式
 @return 0关闭，1协商打开,2只有会议才协商
 */
- (NSInteger)getAudioCodecRed;

/**
 @brief 设置视频发关键帧模式
 @param mode 模式。默认0 RTCP模式；1 INFO模式
 @return 是否成功 0成功； 非0失败
 */
-(NSInteger)setRequestKeyFrameMode:(NSInteger)mode;

/**
 @brief 设置变声
 @param enable 开启与关闭;
 @param pitch 声调调节（变调不变速），取值[-12, 12]（0表示正常，原来声音音调，设置为+8的话，可以听到明显的女生效果）
 @param tempo  音速调节（变速不变调），取值[-50, 50], 0表示正常原语速
 @param callid 电话id
 @return 是否成功 0:成功； 非0失败
 */
-(NSInteger)setMagicSound:(BOOL)enable pitch:(NSInteger)pitch tempo:(NSInteger)tempo ofCallId:(NSString*)callid;
@end
