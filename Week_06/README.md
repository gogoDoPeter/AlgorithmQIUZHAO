学习笔记

1.排序算法
分两类，比较类算法：交换排序（冒泡，快速）
			插入排序（简单插入排序，希尔排序）
			选择排序（简单选择排序，堆排序）
			归并排序（二路归并排序，多路归并排序）
		非比较类排序：计数排序，桶排序，基数排序
		
		扩展：拓扑排序
		对于任何有向图而言，其拓扑排序为其所有结点的一个线性排序（对于同一个有向图而言可能存在多个这样的结点排序）。
		该排序满足这样的条件——对于图中的任意两个结点u和v，若存在一条有向边从u指向v，则在拓扑排序中u一定出现在v前面。
拓扑排序主要用来解决有向图中的依赖解析（dependency resolution）问题。
	举例来说，如果我们将一系列需要运行的任务构成一个有向图，图中的有向边则代表某一任务必须在另一个任务之前完成这一限制。那么运用拓扑排序，我们就能得到满足执行顺序限制条件的一系列任务所需执行的先后顺序。当然也有可能图中并不存在这样一个拓扑顺序，这种情况下我们无法根据给定要求完成这一系列任务，这种情况称为循环依赖（circular dependency）
	前提：
		当且仅当一个有向图为有向无环图（directed acyclic graph，或称DAG）时，才能得到对应于该图的拓扑排序。
		每一个有向无环图都至少存在一种拓扑排序
		
		最常用排序：快速排序，堆排序，归并排序，时间复杂度都是O(nlogn)
空间复杂度,快速O(logn)  堆排序O(1)		归并排序O(n)

