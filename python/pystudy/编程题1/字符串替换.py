def case_insensitive_replace():
    # 输入处理（保持原始大小写）
    pattern = input().strip().lower()  # 转换为小写用于匹配
    replacement = input().strip()
    text = input().strip()
    
    result = []
    i = 0
    pattern_len = len(pattern)
    
    while i <= len(text) - pattern_len:
        # 检查当前位置是否匹配（不区分大小写）
        if text[i:i+pattern_len].lower() == pattern:
            result.append(replacement)
            i += pattern_len  # 跳过已匹配部分
        else:
            result.append(text[i])
            i += 1
    
    # 处理剩余字符
    result.append(text[i:])
    
    return ''.join(result)

# 执行并输出结果
print(case_insensitive_replace())