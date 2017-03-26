//
//  main.m
//  commonType
//
//  Created by 修海锟 on 2017/3/22.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#import <Foundation/Foundation.h>

int main() {
    @autoreleasepool {
        NSLog(@"NSInteger: %ld\nNSUInteger: %ld\nCGFloat: %ld", sizeof(NSInteger), sizeof(NSUInteger), sizeof(CGFloat));
    }
    return 0;
}
