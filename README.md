# 🏆 案例集锦

## 💻 项目环境
### <img src="https://img.shields.io/badge/IDE-Visual%20Studio%202022-5C2D91?logo=visualstudio" alt="VS2022" height="28">

---

## 📌 案例1：选手评分计算

### 🎯 问题描述
有5名选手：选手A、B、C、D、E，10个评委分别对每一名选手打分。  
每位选手的得分计算规则如下：  
1. ⬇️ 去除一个最高分  
2. ⬆️ 去除一个最低分  
3. 🔢 对剩余8个分数取平均值  

### 📊 计算步骤：
```mermaid
graph LR
A[收集10个评委分数] --> B[排序分数]
B --> C[去除最高分]
B --> D[去除最低分]
C --> E[计算平均值]
D --> E
