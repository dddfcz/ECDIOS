//
//  ECCustomerMessageBody.h
//  CCPiPhoneSDK
//
//  Created by xt on 2018/11/6.
//  Copyright © 2018 ronglian. All rights reserved.
//

#import "ECMessageBody.h"

@interface ECCustomerMessageBody : ECMessageBody

@property (nonatomic, copy) NSString *customerData;

@property (nonatomic, assign) int messageType;

@end
