/**
 Copyright (c) 2014-present, Facebook, Inc.
 All rights reserved.
 
 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/NSObject.h>

@protocol POPAnimatorDelegate;

@class POPAnimator;

@protocol POPAnimatorObserving <NSObject>
@required

/**
 @abstract Called on each observer after animator has advanced. Core Animation actions are disabled by default.
 */
- (void)animatorDidAnimate:(POPAnimator *)animator;

/**
 @abstract Called on each observer before animator has advanced. Core Animation actions are disabled by default.
 */
- (void)animatorWillAnimate:(POPAnimator *)animator;

@end
/**
 @abstract The animator class renders animations.
 */
@interface POPAnimator : NSObject

/**
 @abstract The shared animator instance.
 @discussion Consumers should generally use the shared instance in lieu of creating new instances.
 */
+ (instancetype)sharedAnimator;

/**
 @abstract The optional animator delegate.
 */
@property (weak, nonatomic) id<POPAnimatorDelegate> delegate;

/**
 @abstract Add an animator observer. Observer will be notified of each subsequent animator advance until removal.
 */
- (void)addObserver:(id<POPAnimatorObserving>)observer;

/**
 @abstract Remove an animator observer.
 */
- (void)removeObserver:(id<POPAnimatorObserving>)observer;

@end

/**
 @abstract The animator delegate.
 */
@protocol POPAnimatorDelegate <NSObject>

/**
 @abstract Called on each frame before animation application.
 */
- (void)animatorWillAnimate:(POPAnimator *)animator;

/**
 @abstract Called on each frame after animation application.
 */
- (void)animatorDidAnimate:(POPAnimator *)animator;

@end
