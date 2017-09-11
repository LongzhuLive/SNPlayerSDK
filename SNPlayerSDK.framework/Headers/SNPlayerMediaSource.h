//
//  SNPlayerMediaSource.h
//  SNPlayerSDK
//
//  Created by sunshaobing on 2017/2/16.
//  Copyright © 2017年 plu-dev. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 播放源
 */
@interface SNPlayerMediaSource : NSObject


/**
 播放地址，目前支持rtmp、flv、hls
 */
@property (nonatomic, strong, nonnull) NSString *mediaUrl;

/**
 是否点播
 */
@property (nonatomic, assign) BOOL isVod;

@end
