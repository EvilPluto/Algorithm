//
//  main.m
//  DeadLock
//
//  Created by 修海锟 on 2017/3/28.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        dispatch_queue_t myQueue = dispatch_queue_create("my queue", DISPATCH_QUEUE_SERIAL);
        NSLog(@"1");
        dispatch_async(myQueue, ^{
            NSLog(@"2");
            dispatch_sync(myQueue, ^{
                NSLog(@"3");
            });
            NSLog(@"4");
        });
        NSLog(@"5");
    }
    return 0;
}
