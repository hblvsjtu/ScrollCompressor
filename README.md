# ScrollCompressor_Study

## 作者：冰红茶
### 参考文献：[Bell I H. Theoretical and experimental analysis of liquid flooded compression in scroll compressors[J]. Dissertations & Theses - Gradworks, 2011.](https://search.proquest.com/docview/900715003)

### 目的: 翻译和注释Bell I H.的博士学位论文和软件pdSIM，为后面开发电动涡旋压缩机一维热力学模型做准备
        
        
------
        
## 目录
    
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
>>>>>> ![图1-3 公转半径的定义c]()
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


