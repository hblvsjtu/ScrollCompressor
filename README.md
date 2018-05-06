# ScrollCompressor
开发电动涡旋压缩机一维热力学模型
        
        
------
        
##目录
    
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
> - 包含渐开线角度的简单结构
> - double phi_max: 沿渐开线的最大渐开线角
> - double phi_min: 沿渐开线的最小渐开线角
> - double phi_0： 沿着这个渐开线的初始渐开线角度
> - double dphi_max_dtheta: 沿渐开线的最大渐开线角w.r.t.曲柄角的导数
> - double dphi_min_dtheta: The derivative of phi_min w.r.t. crank angle 
> - involute_index(类名) involute: 渐开线的渐开线指数
#### 2) Class：PDSim.scroll.common_scroll_geo.CVInvolutes
> - 
> - CVInvolute Inner: 该腔室的内渐开线的值
> - CVInvolute Outer: 该腔室的外渐开线的值
> - Boolean has_line_1: 是否存在line #1
> - Boolean has_line_2: 是否存在line #2
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
> - 面积积分的对phi的偏导数
        
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
> - 面积积分的对theta的偏导数
        
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
> - 


