//
//  main.m
//  alibaba
//
//  Created by 修海锟 on 2017/3/3.
//  Copyright © 2017年 修海锟. All rights reserved.
//



#import <Foundation/Foundation.h>

// 自定义解析类
@interface DecodeMsg : NSObject

- (NSArray *)getArrayFromString:(NSString *)inputStr; // 分解输入字符串
- (int)getRandomNumFromNumber:(int)longNum; // 获取数字中的随机数
- (int)getByteNumFromNumber:(int)longNum Random:(int)randomNum; // 获取Byte数

@end

@implementation DecodeMsg

- (NSArray *)getArrayFromString:(NSString *)inputStr {
    if (inputStr == nil) {
        exit(1);
    }
    
    NSArray *inputArray = [inputStr componentsSeparatedByString:@","];
    
    return inputArray;
}

- (int)getRandomNumFromNumber:(int)longNum {
    int numberTemp = longNum;
    numberTemp = numberTemp >> 8; // 向右位移8位，将9-16放到最后8位
    
    return 255 - numberTemp;
}

- (int)getByteNumFromNumber:(int)longNum Random: (int)randomNum {
    int lastEightNum = 0;
    int i;
    for (i=0; i<8; i++) {
        if (longNum & 1) {
            lastEightNum += pow(2, i);
        }
        
        longNum = longNum >> 1;
    }
    
    return lastEightNum + randomNum;
}

@end

// 主函数
int main(int argc, const char * argv[]) {
        if (argc != 2) {
            NSLog(@"输入格式错误！");
            exit(1);
        }
        
        // 接受命令行参数
        NSString *inputStr = [NSString stringWithCString:argv[1] encoding:NSUTF8StringEncoding];
        DecodeMsg *decoder = [DecodeMsg new];
        
        NSArray *inputArray = [decoder getArrayFromString:inputStr];
        int arrayLength = (int)[inputArray count]; // 获取字符个数
        int numArray[arrayLength]; // 新建数组储存数字
        
        // 字符串->整形
        int i;
        for (i=0; i<arrayLength; i++) {
            // 如果此处报错，则是输入格式错误
            numArray[i] = [inputArray[i] intValue];
        }
        
        // 创建Byte数组
        Byte byteArray[arrayLength];
        
        // 遍历获取随机数并进行操作
        for (i=0; i<arrayLength; i++) {
            int randomNum = [decoder getRandomNumFromNumber:numArray[i]];
            byteArray[i] = [decoder getByteNumFromNumber:numArray[i] Random:randomNum];        }
        
        // 反转
        for (i=0; i<arrayLength/2; i++) {
            Byte temp = byteArray[i];
            byteArray[i] = byteArray[arrayLength - 1 - i];
            byteArray[arrayLength - 1 - i] = temp;
        }
        
        // 按位取反
        for (i=0; i<arrayLength; i++) {
            byteArray[i] = ~byteArray[i];
        }
        
        // UTF-8解码
        NSData *inputData = [[NSData alloc] initWithBytes:byteArray length:arrayLength];
        NSString *inputMsg = [[NSString alloc] initWithData:inputData encoding:NSUTF8StringEncoding];
        
        // 输出
        NSLog(@"%@", inputMsg);
        //printf("%s", [inputMsg UTF8String]);
    
    return 0;
}
