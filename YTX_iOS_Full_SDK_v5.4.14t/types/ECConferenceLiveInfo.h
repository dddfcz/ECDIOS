//
//  ECConferenceLiveInfo.h
//  CCPiPhoneSDK
//
//  Created by xt on 2018/8/21.
//  Copyright © 2018年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ECConferenceStartLiveRequest : NSObject

/**
 @brief 直播会议id
 */
@property (nonatomic, copy) NSString *conferenceId;

/**
 @brief     是否录像
 */
@property (nonatomic, assign) BOOL isRecord;

/**
 @brief 混屏切换模式 YES 自动， NO 手动
 */
@property (nonatomic, assign) BOOL isAuto;

@end

@interface ECConferenceLiveUrlInfo : NSObject

@property (nonatomic, copy) NSString *rtmpUrl;
@property (nonatomic, copy) NSString *hlsUrl;
@property (nonatomic, copy) NSString *flvUrl;

@end
