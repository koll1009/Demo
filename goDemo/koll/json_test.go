package koll

import (
	"encoding/json"
	"fmt"
	"testing"
)

func TestJsonStruct(t *testing.T) {
	var person struct {
		Name string
		Age  int
	}

	data := []byte(`{"name":"Lumi","age":5}`)

	err := json.Unmarshal(data, &person)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println(person)
}

func TestJsonDynamic(t *testing.T) {
	data := []byte(`
	[{
    "id": 1,
    "name": "Item 1",
    "active": true
	},
	{
		"id": 2,
		"name": "Item 2",
		"active": false
	},
	{
		"id": 200,
		"name": "Item 200",
		"active": true
	}]`)

	schema := make([]map[string]interface{}, 3)

	err := json.Unmarshal(data, &schema)

	fmt.Println(err, schema)
}
