from selenium import webdriver
options = webdriver.ChromeOptions() # 创建一个配置对象
options.add_argument('--proxy-server=http://127.0.0.1:7890') # 使用代理ip

driver = webdriver.Firefox()
