////
////  temp.m
////  alibaba
////
////  Created by 修海锟 on 2017/3/4.
////  Copyright © 2017年 修海锟. All rights reserved.
////
//
//#import <Foundation/Foundation.h>
////
////@interface NSString (URLEncodingAdditions)
////
////- (NSString *)URLEncodedString;
////- (NSString *)URLDecodedString;
////
////@end
////
////@implementation NSString (URLEncodingAdditions)
////
////- (NSString *)URLEncodedString {
////    NSString *result = (NSString *)CFBridgingRelease(CFURLCreateStringByAddingPercentEscapes(kCFAllocatorDefault, (CFStringRef)self, NULL, CFSTR("!*'();:@&=+$,/?%#[]"), kCFStringEncodingUTF8));
////
////    return result;
////}
////
////- (NSString *)URLDecodedString {
////    NSString *result = (NSString *)CFBridgingRelease(CFURLCreateStringByReplacingPercentEscapesUsingEncoding(kCFAllocatorDefault,(CFStringRef)self, CFSTR(""),kCFStringEncodingUTF8));
////
////    return result;
////}
////
////@end
////
////@interface DecodeMsg : NSObject
////
////- (NSArray *)getArrayFromString:(NSString *)inputStr;
////
////@end
////
////@implementation DecodeMsg
////
////- (NSArray *)getArrayFromString:(NSString *)inputStr {
////    if (inputStr == nil) {
////        exit(1);
////    }
////
////    NSArray *inputArray = [inputStr componentsSeparatedByString:@","];
////    return inputArray;
////}
////
////@end
//
//int main(int argc, const char * argv[]) {
//    @autoreleasepool {
//        NSString *inputStr = @"r u OK?";
//        
//        // utf-8转码
//        NSData *dataStr = [inputStr dataUsingEncoding:NSUTF8StringEncoding];
//        int dataLength = (int)[dataStr length];
//        Byte *byteStr = (Byte *)[dataStr bytes];
//        int endArray[dataLength];
//        
//        // 按位取反
//        for (int i=0; i<dataLength; i++) {
//            printf("byte: -- %d\n", byteStr[i]);
//            byteStr[i] = ~byteStr[i];
//            printf("~byte: -- %d\n", byteStr[i]);
//        }
//        
//        // 字节反转
//        for (int j=0; j<dataLength/2; j++) {
//            if (j == dataLength - 1 - j) {
//                break;
//            }
//            Byte temp = byteStr[j];
//            byteStr[j] = byteStr[dataLength - 1 - j];
//            byteStr[dataLength - 1 - j] = temp;
//        }
//        
//        // 生成随机数
//        for (int i=0; i<dataLength; i++) {
//            int randomNum = arc4random() % 100;
//            int randomNumOver = 255 - randomNum;
//            printf("--------------------\nByte:%d\nrandomNum:%d\n",  byteStr[i], randomNum);
//            printf("~randomNum:%d\n", randomNumOver);
//            byteStr[i] = byteStr[i] - randomNum;
//            endArray[i] = byteStr[i] + (randomNumOver << 8);
//            printf("byte:%d\n", byteStr[i]);
//        }
//        
//        for (int i=0; i<dataLength; i++) {
//            printf("%d,", endArray[i]);
//        }
//        
//        //        int num = 62933;
//        //        int a[16];
//        //        for (int i=0; i<16; i++) {
//        //            a[i] = num & 1;
//        //            num = num >> 1;
//        //        }
//        //
//        //        for (int i=15; i>=0; i--) {
//        //            printf("%d", a[i]);
//        //        }
//    }
//    
//    printf("\n");
//    return 0;
//}
