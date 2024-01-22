num_years := 1
DATE := 2023-01-01

# Subtract num_years from DATE
NEW_DATE := $(shell date -d "$(DATE) -$(num_years) year" +"%Y-%m-%d")

# Display results
all:
    @echo "Original DATE: $(DATE)"
    @echo "Updated DATE: $(NEW_DATE)"