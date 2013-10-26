//
//  CUShareCenter.h
//  Example
//
//  Created by curer on 13-10-25.
//  Copyright (c) 2013年 curer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CUShareClient.h"

@class CUPlatFormUserModel;
@class CUPlatFormOAuth;
@class ASIHTTPRequest;
@protocol CUShareClientDataSource <NSObject>

- (id)initWithPlatForm:(PlatFormModel *)model;

#pragma mark - Bind/unBind

- (void)bindSuccess:(void (^)(NSString *message, id data))success
              error:(void (^)(NSString *message, id data))errorBlock;

- (void)unBind;
- (BOOL)isBind;

#pragma mark - userInfo

- (CUPlatFormOAuth *)OAuthInfo;
- (ASIHTTPRequest *)userInfoSuccess:(void (^)(CUPlatFormUserModel *model))success error:(void (^)(id data))errorBlock;

#pragma mark - share

- (void)platForm:(NSString *)platForm
         content:(NSString *)content
         success:(void (^)(id data))success
           error:(void (^)(id error))errorBlock;

- (void)platForm:(NSString *)platForm
         content:(NSString *)content
       imageData:(NSData *)imageData
         success:(void (^)(id data))success
           error:(void (^)(id error))errorBlock;;

- (void)platForm:(NSString *)platForm
         content:(NSString *)content
        imageURL:(NSString *)imageURL
         success:(void (^)(id data))success
           error:(void (^)(id error))errorBlock;

#pragma mark - other
- (void)clear;

- (void)handleOpenURLNofication:(id)notify;

- (BOOL)openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

@end

@class CUShareClientDataSource;
@interface CUShareCenter : NSObject

#pragma mark - connect

/*!
 sina微博
 */
+ (void)connectSinaWeiboWithAppKey:(NSString *)appKey
                         appSecret:(NSString *)appSecret
                       redirectUri:(NSString *)redirectUri;

/*!
 腾讯微博
 */
+ (void)connectTencentWeiboWithAppKey:(NSString *)appKey
                            appSecret:(NSString *)appSecret
                          redirectUri:(NSString *)redirectUri;

/*!
 人人
 */
+ (void)connectRenRenWithAppKey:(NSString *)appKey
                      appSecret:(NSString *)appSecret
                    redirectUri:(NSString *)redirectUri;

/*!
 */
+ (id<CUShareClientDataSource>)clientWithPlatForm:(NSString *)platForm;

/*!
 SSO handle
 */
+ (BOOL)openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

@end