from selenium import webdriver

PATH = "C:\Program Files (x86)\chromedriver.exe"
driver = webdriver.Chrome(PATH)

driver.get("https://web.whatsapp.com/")
print(driver.title)
driver.close() #or driver.quit()