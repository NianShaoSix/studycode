def main():
    import sys
    input = sys.stdin.read().split()
    ptr = 0

    # 读取窗口数量
    N = int(input[ptr])
    ptr += 1
    windows = []
    for _ in range(N):
        window_id = int(input[ptr])
        x1 = int(input[ptr+1])
        y1 = int(input[ptr+2])
        x2 = int(input[ptr+3])
        y2 = int(input[ptr+4])
        ptr += 5
        windows.append({
            'id': window_id,
            'x1': x1,
            'y1': y1,
            'x2': x2,
            'y2': y2
        })
    
    # 初始层次顺序：先输入的窗口在顶层
    # windows列表的顺序就是初始层次顺序（第一个是最顶层）
    
    # 读取点击次数
    M = int(input[ptr])
    ptr += 1
    clicks = []
    for _ in range(M):
        x = int(input[ptr])
        y = int(input[ptr+1])
        ptr += 2
        clicks.append((x, y))
    
    # 处理每次点击
    for x, y in clicks:
        # 从顶层到底层检查（即从前往后遍历windows）
        for i in range(len(windows)):
            win = windows[i]
            if win['x1'] <= x <= win['x2'] and win['y1'] <= y <= win['y2']:
                # 找到点击的窗口，移动到顶层（即移动到列表开头）
                clicked_window = windows.pop(i)
                windows.insert(0, clicked_window)
                break
    # 输出最终窗口层次顺序（从顶层到底层）
    print(' '.join(str(win['id']) for win in windows))

if __name__ == "__main__":
    main()