//
//  ECLiveStreamManager.h
//  CCPiPhoneSDK
//
//  Created by ronglian on 2016/11/7.
//  Copyright © 2016年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#else
#import <AppKit/AppKit.h>
#endif

typedef NS_ENUM(NSUInteger,ECLiveStreamResolution) {
    ECLiveStreamResolution_720P =0,
    ECLiveStreamResolution_HD  = 1,
    ECLiveStreamResolution_QHD = 2,
    ECLiveStreamResolution_SD  = 3,
    ECLiveStreamResolution_LOW = 4
} ;

@protocol ECLiveStreamManager<NSObject>

/**
 @brief 创建直播流
 @return 直播流的唯一标识，用于之后的播放等使用，必须大于0
 */
-(NSInteger)createLiveStream;

/**
 @brief 设置直播显示View
 @param liveStreamID 直播流的唯一标识
 @param view 视频窗口
 @return 0：成功 非0失败
 */
#if TARGET_OS_IPHONE
-(NSInteger)setLiveStream:(NSInteger)handle liveStreamView:(UIView*)view;
#elif TARGET_OS_MAC
-(NSInteger)setLiveStream:(NSInteger)handle liveStreamView:(NSView*)view;
#endif

/**
 @brief 开始观看直播
 @param liveStreamID 直播流的唯一标识
 @param url 直播地址
 @return 0：成功  -1：初始化资源失败 -2：已经在直播或推流  -3：连接失败  -4：建立流失败
 */
-(NSInteger)playLiveStream:(NSInteger)liveStreamID url:(NSString*)url;

/**
 @brief 开始直播推流
 @param liveStreamID 直播流的唯一标识
 @param url 推流地址
 @return 0：成功  -1：初始化资源失败 -2：已经在直播或推流  -3：连接失败  -4：建立流失败
 */
-(NSInteger)pushLiveStream:(NSInteger)liveStreamID url:(NSString*)url;

/**
 @brief 停止观看或推流
 @param liveStreamID 直播流的唯一标识
 @return 0成功；非0失败
 */
-(NSInteger)stopLiveStream:(NSInteger)liveStreamID;

/**
 @brief 释放直播模块
 @param liveStreamID 直播流的唯一标识
 @return 0成功；非0失败
 */
-(NSInteger)releaseLiveStream:(NSInteger)liveStreamID;

/**
 @brief 设置推流视频参数
 @param liveStreamID 直播流的唯一标识
 @param cameraIndex 摄像头index
 @param fps 帧数
 @param autoBitrate 是否自动调整码率
 @param resolution 视频分辨率。当autoBitrate为true时自动调整分辨率
 @return 0：成功　-1：参数不正确
 */
-(NSInteger)setLiveStreamConfig:(NSInteger)handle camera:(NSInteger)cameraIndex fps:(NSInteger)fps autoBitrate:(BOOL)autoBitrate resolution:(ECLiveStreamResolution)resolution;

/**
 @brief 切换摄像头
 @param liveStreamID 直播流的唯一标识
 @param cameraIndex 摄像头index
 @return 0：成功　-1：参数不正确
 */
-(NSInteger)switchLiveStreamCamera:(NSInteger)handle camera:(NSInteger)cameraIndex;

@end
