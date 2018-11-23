# Inverted-Index
- 要求：dictionary 和 postings list 都放在内存。
- 输入：n 个英文 txt 文档，文档名为 1.txt，2.txt，...，n.txt。每个文档的单词都是由一个空格或者标点分割的，不考虑 stemming 和 stop words 去除。
- 输出：1 个 txt 倒排文件。文件中每一行格式为 “term 4 11 12 13 14"，要求按 term 的字典序排列。其中 term 为索引词项，4 是文档数目，11 12 13 14 是四个文档名称。
- 范围：每个文档包括最后的倒排文件均可在内存容纳。
