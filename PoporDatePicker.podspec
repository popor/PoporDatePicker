#
# Be sure to run `pod lib lint PoporDatePicker.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'PoporDatePicker'
  s.version          = '0.01'
  s.summary          = '该仓库复制于 https://github.com/Zws-China/DatePicker , 由于作者使用了xib, 代码无法直接运行; 移除了部分不需要的函数, 标准命名规则;'

  s.homepage         = 'https://github.com/popor/PoporDatePicker'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'popor' => '908891024@qq.com' }
  s.source           = { :git => 'https://github.com/popor/PoporDatePicker.git', :tag => s.version.to_s }
  
  s.ios.deployment_target = '8.0'

  s.source_files = 'Example/Classes/*'
  
end
