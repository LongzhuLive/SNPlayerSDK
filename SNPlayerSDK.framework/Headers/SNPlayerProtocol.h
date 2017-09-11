//
//  SNPlayerProtocol.h
//  SNPlayerSDK
//
//  Created by sunshaobing on 2017/2/16.
//  Copyright © 2017年 plu-dev. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <MediaPlayer/MediaPlayer.h>
#import "SNPlayerDefs.h"
#import "SNPlayerConfig.h"
#import "SNPlayerMediaSource.h"

@protocol SNPlayerProtocol;

/**
 播放器事件代理
 */
@protocol SNPlayerDelegate <NSObject>

@optional

/**
 上报播放器状态变化

 @param snPlayer snPlayer
 @param playerState see SNPlayerState
 
 */
- (void)snPlayer: (nonnull id<SNPlayerProtocol>)snPlayer playerStateDidChanged:(SNPlayerState)playerState;
/**
 播放器停止上报（如果需要知道播放器停止原因可以实现此代理）

 @param snPlayer snPlayer
 @param reason 停止原因，若是内部原因则需要根据internalError来处理
 @param internalError 内部错误，SNPlayerStoppedReasonInternalError时有值
 */
- (void)snPlayer: (nonnull id<SNPlayerProtocol>)snPlayer didStoppedForReason: (SNPlayerStoppedReason)reason andInternalError: (nullable NSError *)internalError;
/**
 上报播放器当前缓冲状态

 @param snPlayer snPlayer
 @param isBuffering 是否正在缓冲
 @param bufferringPercent 缓冲百分比
 */
- (void)snPlayer: (nonnull id<SNPlayerProtocol>)snPlayer isBufferring: (BOOL)isBuffering bufferringPercent:(NSInteger)bufferringPercent;
/**
 上报视频宽高
 @discussion 当播放器第一次解析完或播放中视频宽高发生变化时调用

 @param snPlayer snPlayer
 @param videoSize 当前视频宽高
 */
- (void)snPlayer: (nonnull id<SNPlayerProtocol>)snPlayer videoSizeChanged: (CGSize)videoSize;


@end


/**
 播放器主要接口
 */
@protocol SNPlayerProtocol <NSObject>

#pragma mark - 显示相关
/**
 播放器渲染View，可以将此View加入到想展示的View中，支持自适应大小
 */
@property (nonatomic, readonly, nonnull) UIView* renderView;
/**
 填充模式
 @discussion 此参数设置View的填充模式，支持播放器以及播放中动态设置，建议游戏直播采用MPMovieScalingModeAspectFit，随拍采用MPMovieScalingModeAspectFill
 */
@property(nonatomic, assign) MPMovieScalingMode scalingMode;
/**
 视频显示区域(0,0~1,1)
 @discussion 此参数设置View的显示区域，支持播放器以及播放中动态设置，默认0,0-1,1
 */
@property(nonatomic, assign) CGRect videoDisplayRange;
/**
 播放配置
 @discussion 此参数设置View的显示区域，不强制要求播放中动态设置
 */
@property(nonatomic, strong, nonnull) SNPlayerConfig *playerConfig;

#pragma mark - 事件代理
/**
 事件代理，可以实现此delegate针对相应事件作处理
 */
@property(nonatomic, weak, nullable) id<SNPlayerDelegate> delegate;
#pragma mark - 播放控制

/**
 根据SNPlayerMediaSource以及开始位置（VOD）播放视频流
 @discussion 如果在播放过程中调用此方法会停掉之前的播放重新按照新地址播放

 @param mediaSource 视频源
 @param startPosition 开始播放的位置
 */
- (void)playMediaSource: (nonnull SNPlayerMediaSource *)mediaSource startPosition: (NSTimeInterval) startPosition;
/**
 快进到某个播放位置（点播）

 @param position 播放位置
 */
- (void)seekToPosition: (NSTimeInterval) position;
/**
 暂停
 */
- (void)pause;
/**
 暂停恢复
 */
- (void)resume;
/**
 停止播放
 */
- (void)stop;

#pragma mark - 播放信息获取
/**
 当前播放源
 */
@property (nonatomic, readonly, nullable) SNPlayerMediaSource *mediaSource;
/**
 当前播放状态
 @see SNPlayerState
 */
@property (nonatomic, readonly) SNPlayerState playerState;
/**
 原始视频宽高
 @discussion 只有在SNPlayerStateReady后才能获取到此信息，注意此信息有可能在播放过程中有变化，变化通过delegate通知
 */
@property(nonatomic, readonly) CGSize videoSize;
/**
 播放流所在的服务器IP
 @discussion 只有在SNPlayerStateReady后才能获取到此信息
 */
@property(nonatomic, readonly, nullable) NSString* videoServerIp;
/**
 当前视频时长（点播）
 @discussion 只有在SNPlayerStateReady后才能获取到此信息
 */
@property(nonatomic, readonly) NSTimeInterval duration;
/**
 当前视频播放位置（点播）
 */
@property(nonatomic, readonly) NSTimeInterval position;
/**
 当前视频缓存位置（点播）
 */
@property(nonatomic, readonly) NSTimeInterval cachedPosition;

#pragma mark - 播放器版本获取
/**
 获取播放器版本（xxxplayer_1.0）
 */
+(nonnull NSString *)playerVersionString;

@end
