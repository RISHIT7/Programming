from importlib.resources import contents
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

PATH = "C:\Program Files (x86)\chromedriver.exe"
driver = webdriver.Chrome(PATH)

driver.get("https://youtube.com/")

search = driver.find_element(By.NAME, "search_query")
search.send_keys("ssundee")
search.send_keys(Keys.RETURN)

try:
    main = WebDriverWait(driver, 10).until(
        EC.presence_of_element_located((By.CLASS_NAME, "style-scope ytd-section-list-renderer"))
    )
    print(main.text)
except:
    driver.quit()
#print(driver.page_source)

#time.sleep(5)

driver.quit()