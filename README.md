# ScrollCompressor_Study

## 作者：冰红茶
### 参考文献：[Bell I H. Theoretical and experimental analysis of liquid flooded compression in scroll compressors[J]. Dissertations & Theses - Gradworks, 2011.](https://search.proquest.com/docview/900715003)

### 目的: 翻译和注释Bell I H.的博士学位论文和软件pdSIM，为后面开发电动涡旋压缩机一维热力学模型做准备
        
        
------
        
## 目录
        
### [一、前期准备知识](#1)
#### [1.1 坐标变换](#1.1)   
#### [1.2 面积积分和质心求解](#1.2)
#### [1.3 曲线单位法向量的推导](#1.3)
#### [1.4 单位气体力方向的推导](#1.4)
#### [1.5 基本三角函数基本公式](#1.5)
### [二、基本量](#2)
#### [2.1 动静涡盘点的坐标](#2.1) 
#### [2.2 求解关于初始装配条件下待定系数后的动涡盘等效曲柄转角](#2.2)
#### [2.3 啮合角](#2.3) 
#### [2.4 排气角](#2.4) 
#### [2.5 吸气破入角](#2.5) 
#### [2.6 齿公转半径和壁厚](#2.6)
#### [2.7 工作腔面积的计算](#2.7)
### [三、吸入腔](#3)
#### [3.1 面积体积质心排量计算](#3.1)
#### [3.2 吸入腔内部面积体积质心计算](#3.2)
#### [3.3 气体力与力矩](#3.3)
#### [3.4 吸气面积腔](#3.4)
### [四、压缩腔](#4)
#### [4.1 压缩腔面积体积计算](#4.1)
#### [4.2 压缩比](#4.2)
#### [4.3 压缩腔的质心](#4.3)
#### [4.4 压缩腔的质心](#4.4)
### [四、排气腔](#4)
#### [5.1 压缩腔面积体积计算](#5.1)
#### [5.2 d1腔体积的定义和面积体积质心力和力矩求解](#5.2)
#### [5.3 dd腔体积的定义和面积体积质心力和力矩求解](#5.3)
### [一、PDSim.core package](#1)
#### [1.1 PDSim.core.bearings module](#1.1)
#### [1.2 PDSim.core.callbacks module](#1.2)
#### [1.3 PDSim.core.containers module](#1.3)
#### [1.4 PDSim.core.core module](#1.4)
#### [1.5 PDSim.core.integrators module](#1.5)
#### [1.6 PDSim.core.journal_bearing module](#1.6)
#### [1.7 PDSim.core.mobility module](#1.7)
#### [1.8 PDSim.core.motor module](#1.8)
#### [1.9 module contents](#1.9)
        
### [二、PDSim.flow package](#2)
#### [2.1 PDSim.flow.fanno module](#2.1)
#### [2.2 PDSim.flow.flow module](#2.2)
#### [2.3 PDSim.flow.flow_models module](#2.3)
#### [2.4 module contents](#2.4)
        
### [三、PDSim.misc package](#3)
#### [3.1 PDSim.misc.clipper package](#3.1)
##### [3.1.1 PDSim.misc.clipper.main module](#3.1.1)
##### [3.1.2 PDSim.misc.clipper.pyclipper module](#3.1.2)
##### [3.1.3 PDSim.misc.clipper.setup module](#3.1.3)
##### [3.1.4 module contents](#3.1.4)
#### [3.2 PDSim.misc.datatypes module](#3.2)
#### [3.3 PDSim.misc.error_bar module](#3.3)
#### [3.4 PDSim.misc.hdf5 module](#3.4)
#### [3.5 PDSim.misc.polymath_sample module](#3.5)
#### [3.6 PDSim.misc.scipylike module](#3.6)
#### [3.7 PDSim.misc.solvers module](#3.7)
#### [3.8 PDSim.misc.stl_utilities module](#3.8)
#### [3.9 module contents](#3.9)
        
### [四、PDSim.plot package](#4)
#### [4.1 PDSim.plot.plots module](#4.1)
#### [4.2 module contents](#4.2)
        
### [五、PDSim.recip package](#5)
#### [5.1 PDSim.recip.core module](#5.1)
#### [5.2 module contents](#5.2)
        
### [六、PDSim.scroll package](#6)
#### [6.1 PDSim.scroll.common_scroll_geo module](#6.1)
#### [6.2 PDSim.scroll.core module](#6.2)
#### [6.3 PDSim.scroll.expander module](#6.3)
#### [6.4 PDSim.scroll.plots module](#6.4)
#### [6.5 PDSim.scroll.scroll_geo module](#6.5)
#### [6.6 PDSim.scroll.symm_scroll_geo module](#6.6)
#### [6.7 module contents](#6.7)
        
------
        

<h2 id='1'>一、前期准备知识</h2>
<h3 id='1.1'>1.1 坐标变换</h3> 
        
#### 1) 平移变换和旋转变换
>>>>>> ![图1-4 坐标变换new](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-4%20%E5%9D%90%E6%A0%87%E5%8F%98%E6%8D%A2new.png?raw=true)
        
<h3 id='1.2'>1.2 面积积分和质心求解</h3> 

#### 1) 三角形和曲线面元的推导
> - 图中φ1和φ2的位置错了，应该是逆时针布置才对，遵循右手定律
>>>>>> ![图1-11 三角形和曲线面元的推导](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-11%20%E4%B8%89%E8%A7%92%E5%BD%A2%E5%92%8C%E6%9B%B2%E7%BA%BF%E9%9D%A2%E5%85%83%E7%9A%84%E6%8E%A8%E5%AF%BC.jpg?raw=true)
        
#### 2) 质心的推导
>>>>>> ![图1-13 扇形质心6](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-13%20%E6%89%87%E5%BD%A2%E8%B4%A8%E5%BF%836.png?raw=true)
>>>>>> ![图1-13 扇形质心7](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-13%20%E6%89%87%E5%BD%A2%E8%B4%A8%E5%BF%837.png?raw=true)
>>>>>> ![图1-13 扇形质心8](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-13%20%E6%89%87%E5%BD%A2%E8%B4%A8%E5%BF%838.png?raw=true)
#### 3) 圆渐开线一般面积积分
>>>>>> ![图1-31 圆渐开线一般面积积分](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-31%20%E5%9C%86%E6%B8%90%E5%BC%80%E7%BA%BF%E4%B8%80%E8%88%AC%E9%9D%A2%E7%A7%AF%E7%A7%AF%E5%88%86.jpg?raw=true)
#### 4) 圆渐开线面积质心求解
>>>>>> ![图1-32 圆渐开线面积质心求解](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-32%20%E5%9C%86%E6%B8%90%E5%BC%80%E7%BA%BF%E9%9D%A2%E7%A7%AF%E8%B4%A8%E5%BF%83%E6%B1%82%E8%A7%A3.png?raw=true)
#### 5) 圆渐开线基圆三角形面积求解
>>>>>> ![图1-33 圆渐开线基圆三角形面积求解](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-33%20%E5%9C%86%E6%B8%90%E5%BC%80%E7%BA%BF%E5%9F%BA%E5%9C%86%E4%B8%89%E8%A7%92%E5%BD%A2%E9%9D%A2%E7%A7%AF%E6%B1%82%E8%A7%A3.jpg?raw=true)
        
<h3 id='1.3'>1.3 曲线单位法向量的推导</h3> 
        
>>>>>> ![图1-14 单位法向量](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-14%20%E5%8D%95%E4%BD%8D%E6%B3%95%E5%90%91%E9%87%8F.png?raw=true)
        
<h3 id='1.4'>1.4 单位气体力方向的推导</h3> 
        
>>>>>> ![图1-15 单位气体力方向的推导](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-15%20%E5%8D%95%E4%BD%8D%E6%B0%94%E4%BD%93%E5%8A%9B%E6%96%B9%E5%90%91%E7%9A%84%E6%8E%A8%E5%AF%BC.png?raw=true)
                
<h3 id='1.5'>1.5 基本三角函数基本公式</h3> 
        
>>>>>> ![图1-30 基本三角函数基本公式](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-30%20%E5%9F%BA%E6%9C%AC%E4%B8%89%E8%A7%92%E5%87%BD%E6%95%B0%E5%9F%BA%E6%9C%AC%E5%85%AC%E5%BC%8F.jpg?raw=true)
        
------
        
        
<h2 id='2'>二、基本量</h2>
<h3 id='2.1'>2.1 动静涡盘点的坐标</h3> 
        
>>>>>> ![图1-5 静涡盘各点坐标](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-5%20%E9%9D%99%E6%B6%A1%E7%9B%98%E5%90%84%E7%82%B9%E5%9D%90%E6%A0%87.png?raw=true)
>>>>>> ![图1-7 坐标变换过程](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-7%20%E5%9D%90%E6%A0%87%E5%8F%98%E6%8D%A2%E8%BF%87%E7%A8%8B.png?raw=true)
        
> - 展开角逆时针为正
> - 所以从表达式中我们可以看到动涡盘的第一项都是负的，至于为什么第二项还有一个Δθ呢？这是因为保证在一开始装配的时候就能保持啮合的状态
        
>>>>>> ![图1-6 动涡盘各点坐标](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-6%20%E5%8A%A8%E6%B6%A1%E7%9B%98%E5%90%84%E7%82%B9%E5%9D%90%E6%A0%87.png?raw=true)
     
<h3 id='2.2'>2.2 求解关于初始装配条件下待定系数后的动涡盘等效曲柄转角</h3> 
                
#### 1) 求解求Δθ
> - 所以应该则么求Δθ呢？可以在初始状态的时候，使θ=0，动静涡盘在φie下啮合
    
>>>>>> ![图1-8 动涡盘待定系数求解](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-8%20%E5%8A%A8%E6%B6%A1%E7%9B%98%E5%BE%85%E5%AE%9A%E7%B3%BB%E6%95%B0%E6%B1%82%E8%A7%A3.png?raw=true)
    
> - 求解关于初始装配条件下待定系数后的动涡盘等效曲柄转角
    theta_m = geo.phi_fie - theta + 3.0*pi/2.0 = geo.phi_fie - theta - pi/2.0
        
<h3 id='2.3'>2.3 啮合角求解</h3> 
    
#### 1) 啮合角求解
>>>>>> ![图1-9 各啮合点展开角计算](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-9%20%E5%90%84%E5%95%AE%E5%90%88%E7%82%B9%E5%B1%95%E5%BC%80%E8%A7%92%E8%AE%A1%E7%AE%97.png?raw=true)
        
<h3 id='2.4'>2.4 排气角</h3> 
    
#### 1) 排气角不充分条件和最大腔室对数
> - 其实本质上来讲排气角的条件是啮合角不得小于展开开始角，用这个原则来判断，静涡盘内壁面啮合角φfic=φe-θ-2πNc;动涡盘外壁面啮合角φfic=φe-π-θ-2πNc;
> - 如果采用静涡盘内壁面啮合角φfic = φe-θ-2πNc，则由于φfic > φfis，即φfis < φe-θ-2πNc
> - 如果采用动涡盘内壁面啮合角φoic = φe-π-θ-2πNc，则由于φoic > φois，即φois < φe-π-θ-2πNc
>>>>>> ![图1-10 排气角条件](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-10%20%E6%8E%92%E6%B0%94%E8%A7%92%E6%9D%A1%E4%BB%B6.png?raw=true)
#### 2) 然后利用该不充分条件和最大腔室对数计算排气角
> - floor()函数代表向下取整
>>>>>> ![图1-10 排气角条件2](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-10%20%E6%8E%92%E6%B0%94%E8%A7%92%E6%9D%A1%E4%BB%B62.png?raw=true)
        
<h3 id='2.5'>2.5 吸气破入点</h3> 
        
#### 1) 吸气破入点的三种定义
> - 第一种定义：固定在动涡盘外壁面，当地展开角固定为为φie-π
> - 第二种定义：固定在动涡盘外壁面，该点在静涡盘展开结束角的法线与动涡盘外壁面的交点处
> - 第三种定义：固定在动涡盘外壁面，该点在静涡盘内壁面展开结束角的终点跟静涡盘基圆圆心的连线，与动涡盘外壁面的交点处
>>>>>> ![图1-23 吸气破入点的三种定义](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-23%20%E5%90%B8%E6%B0%94%E7%A0%B4%E5%85%A5%E7%82%B9%E7%9A%84%E4%B8%89%E7%A7%8D%E5%AE%9A%E4%B9%89.png?raw=true)
        
<h3 id='2.6'>2.6 公转半径和壁厚</h3> 
     
#### 1) ro orbiting radius 公转半径
> - 公转半径只是涡盘基圆半径和内外表面发生角的函数
>>>>>> ![图1-3 公转半径的定义c](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-3%20%E5%85%AC%E8%BD%AC%E5%8D%8A%E5%BE%84%E7%9A%84%E5%AE%9A%E4%B9%89c.png?raw=true)
#### 1) t 壁厚
> - t The thickness of the scroll 涡旋的厚度 t=ts = rb*(phi_i0 - phi_o0)，涡旋盘厚度通常为5毫米量级。 
>>>>>> ![图1-1 涡旋的内外表面](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-1%20%E6%B6%A1%E6%97%8B%E7%9A%84%E5%86%85%E5%A4%96%E8%A1%A8%E9%9D%A2.png?raw=true)
        
<h3 id='2.7'>2.7 工作腔面积的计算</h3> 
     
#### 1) 利用刘老师书上的方法，但是壁厚这里我采用了文献的方法
>>>>>> ![图1-29 工作腔面积的计算](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-29%20%E5%B7%A5%E4%BD%9C%E8%85%94%E9%9D%A2%E7%A7%AF%E7%9A%84%E8%AE%A1%E7%AE%97.png?raw=true)
        
------
        

<h2 id='3'>三、吸入腔</h2>
<h3 id='3.1'>3.1 吸入腔外部面积体积质心计算</h3> 
            
#### 1) 吸入腔外部面积体积计算
>>>>>> ![图1-19 吸入腔静涡旋面积体积计算](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-19%20%E5%90%B8%E5%85%A5%E8%85%94%E9%9D%99%E6%B6%A1%E6%97%8B%E9%9D%A2%E7%A7%AF%E4%BD%93%E7%A7%AF%E8%AE%A1%E7%AE%97.png?raw=true)
#### 2) 吸入腔静涡旋质心计算
>>>>>> ![图1-13 扇形质心](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-13%20%E6%89%87%E5%BD%A2%E8%B4%A8%E5%BF%83.png?raw=true)
        
> -  密度偏移，要注意的一点是求质心坐标的时候，分子里面的坐标要求是微元的重心坐标，对于矩形微元而言重心坐标即在其中心，但是在扇形微元的时候，重心在其半径的2/3处的地方，造成了所谓的“密度偏移”
>>>>>> ![图1-20 吸入腔静涡旋质心计算](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-20%20%E5%90%B8%E5%85%A5%E8%85%94%E9%9D%99%E6%B6%A1%E6%97%8B%E8%B4%A8%E5%BF%83%E8%AE%A1%E7%AE%97.png?raw=true)
    
<h3 id='3.2'>3.2 吸入腔内部面积体积质心计算</h3> 
        
#### 1) 吸入腔内部面积体积质心计算
> - 吸入腔内部涡旋面积体积质心计算
>>>>>> ![图1-19 吸入腔静涡旋面积体积计算](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-21%20%E5%86%85%E9%83%A8%E6%B6%A1%E6%97%8B%E9%9D%A2%E7%A7%AF%E4%BD%93%E7%A7%AF%E8%B4%A8%E5%BF%83%E8%AE%A1%E7%AE%97.png?raw=true)
#### 2) 吸入腔内部面积体积质心计算PartA
>>>>>> ![图1-21 内部涡旋面积体积质心计算part_a](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-21%20%E5%86%85%E9%83%A8%E6%B6%A1%E6%97%8B%E9%9D%A2%E7%A7%AF%E4%BD%93%E7%A7%AF%E8%B4%A8%E5%BF%83%E8%AE%A1%E7%AE%97part_a.png?raw=true)
#### 3) 吸入腔内部涡旋涡旋面积体积质心计算PartB
>>>>>> ![图1-21 内部涡旋面积体积质心计算part_b](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-21%20%E5%86%85%E9%83%A8%E6%B6%A1%E6%97%8B%E9%9D%A2%E7%A7%AF%E4%BD%93%E7%A7%AF%E8%B4%A8%E5%BF%83%E8%AE%A1%E7%AE%97part_b.png?raw=true)
#### 4) 吸入腔内部涡旋涡旋面积体积质心计算PartC
>>>>>> ![图1-21 内部涡旋面积体积质心计算part_c](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-21%20%E5%86%85%E9%83%A8%E6%B6%A1%E6%97%8B%E9%9D%A2%E7%A7%AF%E4%BD%93%E7%A7%AF%E8%B4%A8%E5%BF%83%E8%AE%A1%E7%AE%97part_c.png?raw=true)
#### 5) 吸入腔总的面积体积质心和排量的计算
> - 吸入腔总的面积体积质心计算
> - 压缩机排量定义为动涡盘转一圈后的瞬间吸入腔的总体积，但是这个我没有推过，不知道排量的公式对还是错
>>>>>> ![图1-24 吸入腔总的面积体积质心排量计算](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-24%20%E5%90%B8%E5%85%A5%E8%85%94%E6%80%BB%E7%9A%84%E9%9D%A2%E7%A7%AF%E4%BD%93%E7%A7%AF%E8%B4%A8%E5%BF%83%E6%8E%92%E9%87%8F%E8%AE%A1%E7%AE%97.png?raw=true)
           
<h3 id='3.3'>3.3 气体力与力矩</h3> 
        
#### 1) 气体力和力矩的推导
>>>>>> ![图1-17 气体力推导](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-17%20%E6%B0%94%E4%BD%93%E5%8A%9B%E6%8E%A8%E5%AF%BC.png?raw=true)
#### 2) 气体力矩方向的推导
> - 中间是叉乘，rO is a vector from (xO, yO)，φie-pi/2之前也讲过，是动涡盘和曲柄销的安装角度
>>>>>> ![图1-18 力矩推导](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-18%20%E5%8A%9B%E7%9F%A9%E6%8E%A8%E5%AF%BC.png?raw=true)
#### 3) 证明过程
> - 吸气腔水平面力和力矩的计算  但是在计算力矩的时候有点奇怪，按道理来讲，应该有一个因子是关于回转半径ro的，但是这里没有，只有rb平方。
>>>>>> ![图1-26 吸气腔水平面力和力矩的计算](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-26%20%E5%90%B8%E6%B0%94%E8%85%94%E6%B0%B4%E5%B9%B3%E9%9D%A2%E5%8A%9B%E5%92%8C%E5%8A%9B%E7%9F%A9%E7%9A%84%E8%AE%A1%E7%AE%97.png?raw=true)
#### 4) 吸气腔轴向力的计算
>>>>>> ![图1-25 吸气腔轴向力的计算](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-25%20%E5%90%B8%E6%B0%94%E8%85%94%E8%BD%B4%E5%90%91%E5%8A%9B%E7%9A%84%E8%AE%A1%E7%AE%97.png?raw=true) 
           
<h3 id='3.4'>3.4 吸气面积腔</h3> 
        
#### 1) 定义
> - 其实就是在花篮中涡旋盘以外的区域
> - 吸气面积腔，其实这个腔并不是很重要，因为以来这里是用来引导进气，二来这个区域一般有有其他用于加工过程的金属占据着空间
> - 可以大概认为可以使用对称面积*2的方法，但是这个方法不是绝对精确的，因为吸入破入角对于静涡盘和动涡盘来讲是不相同的 
>>>>>> ![图1-27 吸气面积腔的定义](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-27%20%E5%90%B8%E6%B0%94%E9%9D%A2%E7%A7%AF%E8%85%94%E7%9A%84%E5%AE%9A%E4%B9%89.png?raw=true) 
#### 2) 求解面积体积力和力矩
>>>>>> ![图1-28 吸气面积腔的面积体积力个力矩](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-28%20%E5%90%B8%E6%B0%94%E9%9D%A2%E7%A7%AF%E8%85%94%E7%9A%84%E9%9D%A2%E7%A7%AF%E4%BD%93%E7%A7%AF%E5%8A%9B%E4%B8%AA%E5%8A%9B%E7%9F%A9.png?raw=true) 
        
------
        
    
<h2 id='4'>四、压缩腔</h2>
<h3 id='4.1'>4.1 压缩腔面积体积计算</h3>     

#### 1) 文献中的方法，我对内部面积的求解方法心存怀疑
>>>>>> ![图4-2 压缩腔面积计算_文献](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-2%20%E5%8E%8B%E7%BC%A9%E8%85%94%E9%9D%A2%E7%A7%AF%E8%AE%A1%E7%AE%97_%E6%96%87%E7%8C%AE.png?raw=true) 
#### 2) 刘振全老师的方法，我对与直接在内部区域的展开角减π的做法心存怀疑
>>>>>> ![图4-2 压缩腔面积计算_刘老师.jpg](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-2%20%E5%8E%8B%E7%BC%A9%E8%85%94%E9%9D%A2%E7%A7%AF%E8%AE%A1%E7%AE%97_%E5%88%98%E8%80%81%E5%B8%88.jpg?raw=true)
#### 3) 我把前面两种方法结合在一起后，做出的结果跟文献中的形式基本相同
>>>>>> ![图4-2 压缩腔面积计算_冰红茶](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-2%20%E5%8E%8B%E7%BC%A9%E8%85%94%E9%9D%A2%E7%A7%AF%E8%AE%A1%E7%AE%97_%E5%86%B0%E7%BA%A2%E8%8C%B6.png?raw=true)
        
<h3 id='4.2'>4.2 压缩比</h3>     
        
> - 文献中的方法，我试过是正确的
>>>>>> ![图4-3 压缩比1](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-3%20%E5%8E%8B%E7%BC%A9%E6%AF%941.png?raw=true)
> - 我的方法，形式跟文献的基本一致
>>>>>> ![图4-3 压缩比2](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-3%20%E5%8E%8B%E7%BC%A9%E6%AF%942.jpg?raw=true)
        
<h3 id='4.3'>4.3 压缩腔的质心</h3>     
        
> - 关于压缩腔的质心的证明实在太麻烦了，这里我没有去验证
>>>>>> ![图4-4 压缩腔的质心](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-4%20%E5%8E%8B%E7%BC%A9%E8%85%94%E7%9A%84%E8%B4%A8%E5%BF%83.png?raw=true)
        
<h3 id='4.4'>4.4 压缩腔的质心</h3>     
        
> - 这个没什么好说的，跟吸入腔的计算方法类似
>>>>>> ![图4-5 压缩腔的力和力矩](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-5%20%E5%8E%8B%E7%BC%A9%E8%85%94%E7%9A%84%E5%8A%9B%E5%92%8C%E5%8A%9B%E7%9F%A9.png?raw=true)
        
------
        
    
<h2 id='5'>五、排气腔</h2>
<h3 id='5.1'>5.1 相关定义</h3>     

#### 1) 排期腔的演化
> - 一般过了排气角π/2之后才使得d1和dd压力相等
>>>>>> ![图4-6 压缩腔演化图](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-5%20%E5%8E%8B%E7%BC%A9%E8%85%94%E7%9A%84%E5%8A%9B%E5%92%8C%E5%8A%9B%E7%9F%A9.png?raw=true)
        
<h3 id='5.2'>5.2 d1腔体积的定义和面积体积质心求解</h3>     
        
#### 1) d1腔体积的定义和面积体积质心求解
> - d1和dd腔的分界线是由动盘的φo和静盘的φos+π连线。目的是保证在排气角处分界线的长度为0
> - 面积求解的套路一般都是把动涡盘的参考系转化为静涡盘的参考系
>>>>>> ![图4-8 d1腔面积求解](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-8%20d1%E8%85%94%E9%9D%A2%E7%A7%AF%E6%B1%82%E8%A7%A3.png?raw=true)
> - Ad1 = AO - A1 
> - A1 = A1a + A1b + A1c + A1d   A1将关于动涡盘的面积转化到静涡盘上
> - Ad1 = AO - (A1a + A1b + A1c + A1d)
#### 2) A0的面积体积质心求解
> - 转化为静涡盘的参考系，排气角看起来为什么要加上π，但是你从动涡盘的角度去看，转化为动涡盘的参考系展开角是需要减去π的，此时就剩下φos - φo0了
>>>>>> ![图4-10 A0的面积体积质心求解](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-10%20A0%E7%9A%84%E9%9D%A2%E7%A7%AF%E4%BD%93%E7%A7%AF%E8%B4%A8%E5%BF%83%E6%B1%82%E8%A7%A3.png?raw=true)
#### 3) A1a的面积体积质心求解
> - 动涡盘上的面积通过旋转和平移搬到静涡盘上，展开角不变
>>>>>> ![图4-9 A1a的面积体积质心求解](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-9%20A1a%E7%9A%84%E9%9D%A2%E7%A7%AF%E4%BD%93%E7%A7%AF%E8%B4%A8%E5%BF%83%E6%B1%82%E8%A7%A3.png?raw=true)
#### 4) A1b的面积体积质心求解
> - 动涡盘上的面积通过旋转和平移搬到静涡盘上，展开角不变，运用圆渐开线基圆三角形面积求解的结论可以直接得到答案
>>>>>> ![图4-12 A1b的面积体积质心求解](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-12%20A1b%E7%9A%84%E9%9D%A2%E7%A7%AF%E4%BD%93%E7%A7%AF%E8%B4%A8%E5%BF%83%E6%B1%82%E8%A7%A3.png?raw=true)
#### 5) A1c的面积体积质心求解
> - 运用圆渐开线基圆三角形面积求解的结论可以直接得到答案
>>>>>> ![图4-13 A1c的面积体积质心求解](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-13%20A1c%E7%9A%84%E9%9D%A2%E7%A7%AF%E4%BD%93%E7%A7%AF%E8%B4%A8%E5%BF%83%E6%B1%82%E8%A7%A3.jpg?raw=true)
#### 6) A1d的面积体积质心求解
> - V1d,d1这个三角形比较麻烦，因为它的一个顶点在静涡盘上，另一个顶点在动涡盘上，算起来比较麻烦，这里我就不推导了
>>>>>> ![图4-11 A1d的面积体积质心求解](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-11%20A1d%E7%9A%84%E9%9D%A2%E7%A7%AF%E4%BD%93%E7%A7%AF%E8%B4%A8%E5%BF%83%E6%B1%82%E8%A7%A3.png?raw=true)
#### 7) A1的面积体积质心求解汇总
> - A1 = A1a + A1b + A1c + A1d
>>>>>> ![图4-14 A1的面积体积质心求解](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-14%20A1%E7%9A%84%E9%9D%A2%E7%A7%AF%E4%BD%93%E7%A7%AF%E8%B4%A8%E5%BF%83%E6%B1%82%E8%A7%A3.png?raw=true) 
#### 8) Ad1的面积体积质心求解汇总
> - Ad1 = AO - A1
>>>>>> ![图4-15 Ad1的面积体积质心求解](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-15%20Ad1%E7%9A%84%E9%9D%A2%E7%A7%AF%E4%BD%93%E7%A7%AF%E8%B4%A8%E5%BF%83%E6%B1%82%E8%A7%A3.png?raw=true) 
#### 9) Ad1的力和力矩求解
> - 还是以前的套路
>>>>>> ![图4-16 Ad1的力和力矩求解.png](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE4-16%20Ad1%E7%9A%84%E5%8A%9B%E5%92%8C%E5%8A%9B%E7%9F%A9%E6%B1%82%E8%A7%A3.png?raw=true) 
        
<h3 id='5.3'>5.3 dd腔体积的定义和面积体积质心力和力矩求解</h3>     
        
#### 1) 排期腔的演化
> - 一般过了排气角π/2之后才使得d1和dd压力相等
>>>>>> ![图4-6 压缩腔演化图]()
 
<h2 id='6'>六、PDSim.scroll package</h2>
<h3 id='6.1'>6.1 PDSim.scroll.common_scroll_geo module</h3>  

#### 1) Class：PDSim.scroll.common_scroll_geo.CVInvolute
> - 包含展开角度的简单结构
> - phi: 展开角φ
> - theta: 曲轴转角
> - double phi_max: 沿渐开线的最大展开角
> - double phi_min: 沿渐开线的最小展开角
> - double phi_0： 沿着这个渐开线发生角
> - double dphi_max_dtheta: 沿渐开线的最大展开角对曲轴转角θ的导数
> - double dphi_min_dtheta: 沿渐开线的最小展开角对曲轴转角θ的导数 
> - involute_index(类名) involute: 渐开线的渐开线指数
    
    //一种通用的涡旋角度结构体
    cdef class CVInvolute:
    def __init__(self):
        pass
    
    // 渐开线类别
    cdef enum involute_index:
    INVOLUTE_FI
    INVOLUTE_FO
    INVOLUTE_OI
    INVOLUTE_OO

    // 渐开线类别返回字符串
    cpdef bytes involute_index_to_key(int index):
    """
    Return the string associated with a given index from the common_scroll_geo.involute_index enumeration
    """
    
    if index == INVOLUTE_FI:
        return bytes('fi')
    elif index == INVOLUTE_FO:
        return bytes('fo')
    elif index == INVOLUTE_OI:
        return bytes('oi')
    elif index == INVOLUTE_OO:
        return bytes('oo')
    else:
        return bytes('') 
#### 2) Class：PDSim.scroll.common_scroll_geo.CVInvolutes
> - 
> - CVInvolute Inner: 该腔室的内部渐开线
> - CVInvolute Outer: 该腔室的外部渐开线
> - Boolean has_line_1: 是否存在line #1
> - Boolean has_line_2: 是否存在line #2
    
    //申明内部渐开线和外部渐开线两种角度结构
    cdef class CVInvolutes:
    def __init__(self):
        self.Inner = CVInvolute.__new__(CVInvolute)
        self.Outer = CVInvolute.__new__(CVInvolute)

    //打印用
    def __repr__(self):
        s = ''
        s += "Outer.involute = {i:s}\n".format(i=involute_index_to_key(self.Outer.involute))
        s += "Outer.phi_0 = {i:g}\n".format(i=self.Outer.phi_0)
        s += "Outer.phi_max = {i:g}\n".format(i=self.Outer.phi_max)
        s += "Outer.phi_min = {i:g}\n".format(i=self.Outer.phi_min)
        s += "Inner.involute = {i:s}\n".format(i=involute_index_to_key(self.Inner.involute))
        s += "Inner.phi_0 = {i:g}\n".format(i=self.Inner.phi_0)
        s += "Inner.phi_max = {i:g}\n".format(i=self.Inner.phi_max)
        s += "Inner.phi_min = {i:g}\n".format(i=self.Inner.phi_min)
        s += "has_line_1 = {i:g}\n".format(i=self.has_line_1)
        s += "has_line_2 = {i:g}".format(i=self.has_line_2)
        return s
#### 2) Class：PDSim.scroll.common_scroll_geo.geoVals
> - h 齿高
> - ro orbiting radius 公转半径 公转半径只是涡盘基圆半径和内外表面发生角的函数
>>>>>> ![图1-3 公转半径的定义c](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-3%20%E5%85%AC%E8%BD%AC%E5%8D%8A%E5%BE%84%E7%9A%84%E5%AE%9A%E4%B9%89c.png?raw=true)
> - rb the radius of the base circle 基圆半径
> - t The thickness of the scroll 涡旋的厚度 t=ts = rb*(phi_i0 - phi_o0)，涡旋盘厚度通常为5毫米量级。 
>>>>>> ![图1-1 涡旋的内外表面](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-1%20%E6%B6%A1%E6%97%8B%E7%9A%84%E5%86%85%E5%A4%96%E8%A1%A8%E9%9D%A2.png?raw=true)
> - phi_fie Inner Ending Angle 静涡盘内部渐开线结束角
> - phi_fis Inner Starting Angle 静涡盘内部渐开线开始角
> - phi_fi0 Inner Initial Angle 静涡盘内部渐开线发生角
> - phi_foe Inner Ending Angle 静涡盘外部渐开线结束角
> - phi_fos Inner Starting Angle 静涡盘外部渐开线开始角
> - phi_fo0 Inner Initial Angle 静涡盘外部渐开线发生角
> - phi_oie Inner Ending Angle 动涡盘内部渐开线结束角
> - phi_ois Inner Starting Angle 动涡盘内部渐开线开始角
> - phi_oi0 Inner Initial Angle 动涡盘内部渐开线发生角
> - phi_ooe Inner Ending Angle 动涡盘外部渐开线结束角
> - phi_oos Inner Starting Angle 动涡盘外部渐开线开始角
> - phi_oo0 Inner Initial Angle 动涡盘外部渐开线发生角
> - phi_ie_offset 初始值为0
>>>>>> ![图1-2 角度的定义](https://github.com/hblvsjtu/ScrollCompressor/blob/master/picture/%E5%9B%BE1-2%20%E8%A7%92%E5%BA%A6%E7%9A%84%E5%AE%9A%E4%B9%89.png?raw=true)
> - copy_inplace(self, geoVals target) 结构性复制
> - is_symmetric(self) → bool 动外部渐开线所有角度都相等的时候返回true
> - val_if_symmetric(self, double val) → double 如果is_symmetric则返回数值，否则返回数值错误
> - xvec_disc_port 属于numpy.ndarray类型
> - yvec_disc_port 属于numpy.ndarray类型
> - rebuild_geoVals
> - setattr(x, 'y', v) is equivalent to ``x.y = v''
> - getattr(x, 'y') is equivalent to x.y
> - __repr__ 打印所有属性
    
    #This is a list of all the members in geoVals
    geoValsvarlist=['h','ro','rb','t',
                    'phi_fi0','phi_fis','phi_fie',
                    'phi_fo0','phi_fos','phi_foe',
                    'phi_oi0','phi_ois','phi_oie',
                    'phi_oo0','phi_oos','phi_ooe',
                    'xa_arc1','ya_arc1','ra_arc1','t1_arc1','t2_arc1',
                    'xa_arc2','ya_arc2','ra_arc2','t1_arc2','t2_arc2',
                    'b_line', 't1_line', 't2_line', 'm_line',
                    'x0_wall','y0_wall','r_wall',
                    'delta_radial', 'delta_flank',
                    'phi_ie_offset','delta_suction_offset',
                    'cx_scroll','cy_scroll','V_scroll','Vremove']

    //外部渐开线所有角度都相等的时候返回true
    cpdef bint is_symmetric(self):
        """
        Returns true if all the angles for the fixed scroll are the same as for the orbiting scroll
        """
        return (abs(self.phi_fi0-self.phi_oi0) < 1e-14
                and abs(self.phi_fis-self.phi_ois) < 1e-14
                and abs(self.phi_fie-self.phi_oie) < 1e-14
                and abs(self.phi_fo0-self.phi_oo0) < 1e-14
                and abs(self.phi_fos-self.phi_oos) < 1e-14
                and abs(self.phi_foe-self.phi_ooe) < 1e-14
                )
#### 3) Class：PDSim.scroll.common_scroll_geo.Gr
> - 面积的不定积分项
        
    cpdef double Gr(double phi, geoVals geo, double theta, int inv):
    """
    The antiderivative of the area integration term, where 
    
    .. math::
    
        Gr \\equiv \\int\\left[\\left(-y\\frac{dx(\\phi)}{d\\phi}+x\\frac{dy(\\phi)}{d\\phi}\\right)d\\phi\\right]
    """

    //求解关于初始装配条件下待定系数后的动涡盘等效曲柄转角
    theta_m = geo.phi_fie - theta + 3.0*pi/2.0
    if inv == INVOLUTE_FI:
        return phi*geo.rb**2*(phi**2 - 3*phi*geo.phi_fi0 + 3*geo.phi_fi0**2)/3
    elif inv == INVOLUTE_FO:
        return phi*geo.rb**2*(phi**2 - 3*phi*geo.phi_fo0 + 3*geo.phi_fo0**2)/3
    elif inv == INVOLUTE_OI:
        return geo.rb*(phi**3*geo.rb - 3*phi**2*geo.phi_oi0*geo.rb 
                       + 3*phi*geo.phi_oi0**2*geo.rb 
                       + 3*(phi-geo.phi_oi0)*geo.ro*cos(phi - theta_m)
                       - 3*geo.ro*sin(phi - theta_m))/3
    elif inv == INVOLUTE_OO:
        return geo.rb*(phi**3*geo.rb - 3*phi**2*geo.phi_oo0*geo.rb 
                       + 3*phi*geo.phi_oo0**2*geo.rb 
                       + 3*(phi-geo.phi_oo0)*geo.ro*cos(phi - theta_m) 
                       - 3*geo.ro*sin(phi - theta_m))/3
> - 面积积分的对展开角φ的偏导数
        
    cpdef double dGr_dphi(double phi, geoVals geo, double theta, int inv):
    """
    The partial derivative of Gr with respect to phi with theta held constant
    """
    
    THETA = geo.phi_fie - theta - pi/2.0
    
    if inv == INVOLUTE_FI:
        return geo.rb**2*(phi - geo.phi_fi0)**2
    elif inv == INVOLUTE_FO:
        return geo.rb**2*(phi - geo.phi_fo0)**2
    elif inv == INVOLUTE_OI:
        return geo.rb*(geo.rb*(phi - geo.phi_oi0)**2 + (phi- geo.phi_oi0)*geo.ro*sin(THETA - phi))
    elif inv == INVOLUTE_OO:
        return geo.rb*(geo.rb*(phi - geo.phi_oo0)**2 + (phi- geo.phi_oo0)*geo.ro*sin(THETA - phi))
> - 面积积分的对曲轴转角θ的偏导数
        
    cpdef double dGr_dtheta(double phi, geoVals geo, double theta, int inv):
    """
    The partial derivative of Gr with respect to theta with phi held constant
    """
    
    THETA = geo.phi_fie - theta - pi/2.0
    
    if inv == INVOLUTE_FI or inv == INVOLUTE_FO:
        return 0.0
    elif inv == INVOLUTE_OI:
        return geo.rb*geo.ro*((phi - geo.phi_oi0)*sin(THETA - phi) - cos(THETA - phi))
    elif inv == INVOLUTE_OO:
        return geo.rb*geo.ro*((phi - geo.phi_oo0)*sin(THETA - phi) - cos(THETA - phi))
#### 4) class PDSim.scroll.common_scroll_geo.HTAnglesClass
> - 与涡旋压缩机腔室传热计算所需计算有关的角度的结构
> - double phi_1_i 内部渐开线外壁最大展开角
> - double phi_2_i 内部渐开线外壁最小展开角
> - double phi_1_o 外部渐开线内壁最大展开角
> - double phi_2_o 外部渐开线内壁最小展开角
> - double phi_i0 内部渐开线外壁原始展开角
> - double phi_o0 外部渐开线内壁原始展开角
        
    cdef class HTAnglesClass:
    def __repr__(self):
        s = ''
        for k in ['phi_1_i','phi_2_i','phi_1_o','phi_2_o','phi_i0','phi_o0']:
            s += k + ' : ' + str(getattr(self,k)) + '\n'
        return s
#### 5) PDSim.scroll.common_scroll_geo.VdV
> - 以一种通用的方式评估V和dV/dtheta\[m^3/radian\]
> - cpdef VdVstruct VdV(double theta, geoVals geo, CVInvolutes inv)
    
    cpdef VdVstruct VdV(double theta, geoVals geo, CVInvolutes inv):
    """
    Evaluate V and dV/dtheta in a generalized manner for a chamber
    """
    cdef double A_i, A_o, A_line_1 = 0, A_line_2 = 0, x_1, x_2, y_1, y_2, dx_1_dphi=0, dy_1_dphi=0, dx_2_dphi=0, dy_2_dphi=0
    cdef double dA_line_1_dtheta = 0, dA_line_2_dtheta = 0, dx_1_dtheta, dy_1_dtheta, dx_2_dtheta, dy_2_dtheta

    ## ------------------------ VOLUME -------------------------------

    A_i = 0.5*(Gr(inv.Outer.phi_max, geo, theta, inv.Outer.involute) - Gr(inv.Outer.phi_min, geo, theta, inv.Outer.involute))
    if inv.has_line_1:
        _coords_inv_d_int(inv.Outer.phi_max, geo, theta, inv.Outer.involute, &x_1, &y_1)
        _coords_inv_d_int(inv.Inner.phi_max, geo, theta, inv.Inner.involute, &x_2, &y_2)
        A_line_1 = 0.5*(x_1*y_2 - x_2*y_1)
    A_o = 0.5*(Gr(inv.Inner.phi_min, geo, theta, inv.Inner.involute) - Gr(inv.Inner.phi_max, geo, theta, inv.Inner.involute))
    if inv.has_line_2:
        _coords_inv_d_int(inv.Inner.phi_min, geo, theta, inv.Inner.involute, &x_1, &y_1)
        _coords_inv_d_int(inv.Outer.phi_min, geo, theta, inv.Outer.involute, &x_2, &y_2)
        A_line_2 = 0.5*(x_1*y_2 - x_2*y_1)
    
    V = geo.h*(A_i + A_line_1 + A_o + A_line_2)
    
    ## ------------------------ DERIVATIVE -------------------------------
    
    dA_i_dtheta = 0.5*(dGr_dphi(inv.Outer.phi_max, geo, theta, inv.Outer.involute)*inv.Outer.dphi_max_dtheta
                      +dGr_dtheta(inv.Outer.phi_max, geo, theta, inv.Outer.involute)
                      -dGr_dphi(inv.Outer.phi_min, geo, theta, inv.Outer.involute)*inv.Outer.dphi_min_dtheta
                      -dGr_dtheta(inv.Outer.phi_min, geo, theta, inv.Outer.involute)
                      )

    if inv.has_line_1:
        coords_inv_dtheta(inv.Outer.phi_max, geo, theta, inv.Outer.involute, &dx_1_dtheta, &dy_1_dtheta)
        coords_inv_dtheta(inv.Inner.phi_max, geo, theta, inv.Inner.involute, &dx_2_dtheta, &dy_2_dtheta)
        _dcoords_inv_dphi_int(inv.Outer.phi_max, geo, theta, inv.Outer.involute, &dx_1_dphi, &dy_1_dphi)
        dx_1_dtheta += dx_1_dphi*inv.Outer.dphi_max_dtheta
        dy_1_dtheta += dy_1_dphi*inv.Outer.dphi_max_dtheta
        _dcoords_inv_dphi_int(inv.Inner.phi_max, geo, theta, inv.Inner.involute, &dx_2_dphi, &dy_2_dphi)
        dx_2_dtheta += dx_2_dphi*inv.Inner.dphi_max_dtheta
        dy_2_dtheta += dy_2_dphi*inv.Inner.dphi_max_dtheta
        dA_line_1_dtheta = 0.5*(x_1*dy_2_dtheta + y_2*dx_1_dtheta - x_2*dy_1_dtheta - y_1*dx_2_dtheta)
    
    dA_o_dtheta = 0.5*(dGr_dphi(inv.Inner.phi_min, geo, theta, inv.Inner.involute)*inv.Inner.dphi_min_dtheta
                       +dGr_dtheta(inv.Inner.phi_min, geo, theta, inv.Inner.involute)
                       -dGr_dphi(inv.Inner.phi_max, geo, theta, inv.Inner.involute)*inv.Inner.dphi_max_dtheta
                       -dGr_dtheta(inv.Inner.phi_max, geo, theta, inv.Inner.involute)
                       )

    if inv.has_line_2:
        coords_inv_dtheta(inv.Inner.phi_min, geo, theta, inv.Inner.involute, &dx_1_dtheta, &dy_1_dtheta)
        coords_inv_dtheta(inv.Outer.phi_min, geo, theta, inv.Outer.involute, &dx_2_dtheta, &dy_2_dtheta)

        _dcoords_inv_dphi_int(inv.Inner.phi_min, geo, theta, inv.Inner.involute, &dx_1_dphi, &dy_1_dphi)
        dx_1_dtheta += dx_1_dphi*inv.Inner.dphi_min_dtheta
        dy_1_dtheta += dy_1_dphi*inv.Inner.dphi_min_dtheta
        _dcoords_inv_dphi_int(inv.Outer.phi_min, geo, theta, inv.Outer.involute, &dx_2_dphi, &dy_2_dphi)
        dx_2_dtheta += dx_2_dphi*inv.Outer.dphi_min_dtheta
        dy_2_dtheta += dy_2_dphi*inv.Outer.dphi_min_dtheta

        dA_line_2_dtheta = 0.5*(x_1*dy_2_dtheta + y_2*dx_1_dtheta - x_2*dy_1_dtheta - y_1*dx_2_dtheta)

    dV = geo.h*(dA_i_dtheta + dA_line_1_dtheta + dA_o_dtheta + dA_line_2_dtheta)
    
    cdef VdVstruct VdV = VdVstruct.__new__(VdVstruct)
    VdV.V = V
    VdV.dV = dV
    return VdV
#### 6) class PDSim.scroll.common_scroll_geo.coords_inv
> - 对应于沿着渐开线（外部渐开线盘内部[fi]，外部渐开线盘外部渐开线[fo]，内部渐开线外部渐开线[oo]和内部渐开线内部渐开线[oi]）的点的渐开线角度
> - coords_inv(phi, geoVals geo, double theta, flag='fi') → tuple
> - phi_vec – 渐开线角度的一维数字数组或双精度矢量
> - geo – geoVals class scroll compressor geometry
> - theta – 单精度曲轴转角θ 0~2π
> - flag – 渐开线字符串flag： ‘fi’,’fo’,’oi’,’oo’
> - return - 涡旋盘坐标元组(数组) 如：(x,y)
    
    def coords_inv(phi,geo,theta,flag="fi")
    if type(phi) is np.ndarray:
        return _coords_inv_np(phi,geo,theta,flag)
    else:
        return _coords_inv_d(phi,geo,theta,flag)
    
    //
    cpdef tuple _coords_inv_np(np.ndarray[np.float_t] phi, geoVals geo,double theta, flag=""):
    """
    Internal function that does the calculation if phi is definitely a 1D numpy vector
    """
    rb = geo.rb
    ro = rb*(pi - geo.phi_fi0 + geo.phi_oo0)
    om = geo.phi_fie - theta + 3.0*pi/2.0

    if flag=="fi":
        x = rb*np.cos(phi)+rb*(phi-geo.phi_fi0)*np.sin(phi)
        y = rb*np.sin(phi)-rb*(phi-geo.phi_fi0)*np.cos(phi)
    elif flag=="fo":
        x = rb*np.cos(phi)+rb*(phi-geo.phi_fo0)*np.sin(phi)
        y = rb*np.sin(phi)-rb*(phi-geo.phi_fo0)*np.cos(phi)
    elif flag=="oi":
        x = -rb*np.cos(phi)-rb*(phi-geo.phi_oi0)*np.sin(phi)+ro*np.cos(om)
        y = -rb*np.sin(phi)+rb*(phi-geo.phi_oi0)*np.cos(phi)+ro*np.sin(om)
    elif flag=="oo":
        x = -rb*np.cos(phi)-rb*(phi-geo.phi_oo0)*np.sin(phi)+ro*np.cos(om)
        y = -rb*np.sin(phi)+rb*(phi-geo.phi_oo0)*np.cos(phi)+ro*np.sin(om)
    else:
        raise ValueError('flag not valid')
    return (x,y)

    //
    cpdef tuple _coords_inv_d(double phi, geoVals geo,double theta, flag=""):
    """
    Internal function that does the calculation if phi is a double variable 
    """

    rb = geo.rb
    ro = rb*(pi - geo.phi_fi0 + geo.phi_oo0)
    om = geo.phi_fie - theta + 3.0*pi/2.0

    if flag=="fi":
        x = rb*cos(phi)+rb*(phi-geo.phi_fi0)*sin(phi)
        y = rb*sin(phi)-rb*(phi-geo.phi_fi0)*cos(phi)
    elif flag=="fo":
        x = rb*cos(phi)+rb*(phi-geo.phi_fo0)*sin(phi)
        y = rb*sin(phi)-rb*(phi-geo.phi_fo0)*cos(phi)
    elif flag=="oi":
        x = -rb*cos(phi)-rb*(phi-geo.phi_oi0)*sin(phi)+ro*cos(om)
        y = -rb*sin(phi)+rb*(phi-geo.phi_oi0)*cos(phi)+ro*sin(om)
    elif flag=="oo":
        x = -rb*cos(phi)-rb*(phi-geo.phi_oo0)*sin(phi)+ro*cos(om)
        y = -rb*sin(phi)+rb*(phi-geo.phi_oo0)*cos(phi)+ro*sin(om)
    else:
        raise ValueError('flag not valid')
    return (x,y) 


