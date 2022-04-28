<style>
strong {
    color:#00F9A5;
    size: 100px;
    margin: 0em;
    font-size: xx-large;
    font-style: italic;
}
</style>

# 深度优先搜索

从一个节点出发，使用 DFS 对一个图进行遍历时，能够遍历到的节点都是从初始节点可达的，DFS 常用来求解这种 **可达性**  问题。

# 在程序实现 DFS 时需要考虑以下问题：

1. 栈：用栈来保存当前节点信息，当遍历新节点返回时能够继续遍历当前节点。可以使用递归栈。
2. 标记：和 BFS 一样同样需要对已经遍历过的节点进行标记。