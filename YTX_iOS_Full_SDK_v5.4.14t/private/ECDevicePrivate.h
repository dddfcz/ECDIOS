//
//  ECDevicePrivate.h
//  CCPiPhoneSDK
//
//  Created by jiazy on 2017/12/20.
//  Copyright © 2017年 ronglian. All rights reserved.
//

@protocol ECDevicePrivate<NSObject>

/**
 @brief 设置是否获取全部离线消息
 @param enable 是否全部
 */
- (void)setReceiveAllOfflineMsgEnabled:(BOOL)enable;

/**
 @brief 设置是否获取全部离线消息
 @param enable 是否全部
 */
- (void)setIsOpenOfflineSwitch:(BOOL)enable;

/**
 @brief 设置用于判断https类型的端口
 @param connectorPort 连接服务器端口，默认28050
 @param fPort 文件服务器端口，默认28090
 @param lPort 下载服务器端口，默认28888
 */
- (void)setHttpsCNTPort:(int)connectorPort FilePort:(int)fPort LVSPort:(int)lPort;

/**
 @brief 设置sdk是否走加密通道。一旦开启，就会走加密通道逻辑，必须保证服务器已支持加密。
 @param isCNTSecure 连接服务器加密开关，默认关闭
 @param isFileSecure 文件服务器加密开关，默认关闭
 @param isLvsSecure 下载服务器加密开关，默认关闭
 */
-(void)enableSecureTansportCNT:(BOOL)isCNTSecure FileServer:(BOOL)isFileSecure LvsServer:(BOOL)isLvsSecure;

/**
 @brief 设置AppServer地址
 @param available 是否支持appserver
 @param address appserver地址，支持域名
 @param port appserver端口
 @param ishttps 是否https访问
 */
- (NSInteger)setAppServer:(BOOL)available DNS:(NSString*)address port:(NSInteger)port isHttps:(BOOL)ishttps;
@end
