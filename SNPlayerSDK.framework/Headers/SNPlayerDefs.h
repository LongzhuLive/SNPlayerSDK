//
//  SNPlayerDefs.h
//  SNPlayerSDK
//
//  Created by sunshaobing on 2017/2/16.
//  Copyright © 2017年 plu-dev. All rights reserved.
//

#ifndef SNPlayerDefs_h
#define SNPlayerDefs_h

typedef enum : NSUInteger {
    ///播放器已停止
    SNPlayerStateStopped,
    ///SNPlayerStateStopped->(play: playMediaSource)->SNPlayerStatePreparing
    SNPlayerStatePreparing,
    ///流已解析完成
    SNPlayerStateReady,
    ///已经进入播放状态
    SNPlayerStatePlaying,
    ///暂停中
    SNPlayerStatePaused
} SNPlayerState;


typedef enum : NSUInteger {
    ///用户调用stop
    SNPlayerStoppedReasonUserExit,
    ///播放结束
    SNPlayerStoppedReasonEnded,
    ///内部错误（详细根据NSError获取）
    SNPlayerStoppedReasonInternalError
} SNPlayerStoppedReason;




#endif /* SNPlayerDefs_h */
