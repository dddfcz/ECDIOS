//
//  ECLiveStreamDelegate.h
//  CCPiPhoneSDK
//
//  Created by ronglian on 2016/11/7.
//  Copyright © 2016年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger,ECLiveStreamStatusCode) {
    ECLiveStreamStatusCode_Connecting   = 0,
    ECLiveStreamStatusCode_ConnectSuccess=1,
    ECLiveStreamStatusCode_ConnectFailed =2,
    ECLiveStreamStatusCode_TimeOut      = 3,
    ECLiveStreamStatusCode_PushSuccess  = 4,
    ECLiveStreamStatusCode_PushFailed   = 5,
    ECLiveStreamStatusCode_PlaySuccess  = 6,
    ECLiveStreamStatusCode_PlayFailed   = 7,
    ECLiveStreamStatusCode_Disconnected = 8,
    ECLiveStreamStatusCode_Finished = 9
};


/**
 * 直播功能回调代理
 */
@protocol ECLiveStreamDelegate<NSObject>
@optional
/**
 @brief 直播连接回调
 @param status ECLiveStreamStatusCode 直播网络状态
  */
 -(void) onLiveStreamNetworkStatus:(ECLiveStreamStatusCode)status;
@end
