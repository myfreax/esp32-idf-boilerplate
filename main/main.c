#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char* TAG = "RELEASE";

void app_main(void) {
  while (1) {
    ESP_LOGI(TAG, "feat");
    ESP_LOGI(TAG, "refactor");
    ESP_LOGI(TAG, "fix");
    ESP_LOGI(TAG, "build");
    ESP_LOGI(TAG, "chore");
    ESP_LOGI(TAG, "docs");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}