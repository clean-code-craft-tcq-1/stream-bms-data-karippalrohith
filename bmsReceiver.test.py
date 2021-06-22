import unittest
import json
from bmsReceiver import bmsReceiver

class BmsStreamingTest(unittest.TestCase):
    def test_calculat4e_moving_avaerage(self):
        moving_average_window = 5
        moving_average_calculated = bmsReceiver.calculate_moving_average(bms_param)
        moving_average_temp = sum(bms_param['Temperature'][-5:]) / moving_average_window
        moving_average_soc = sum(bms_param['SOC'][-5:]) / moving_average_window
        self.assertEqual(moving_average_calculated['Temperature'], moving_average_temp)
        self.assertEqual(moving_average_calculated['SOC'], moving_average_soc)        
    
    def test_min_max_calculator(self):
        max_calcualted, min_calculated = bmsReceiver.min_max_calculator(bms_param['Temperature'])
        max_actual = 92.7
        min_actual = 12
        self.assertEqual(max_calcualted, max_actual)
        self.assertEqual(min_calculated, min_actual)
        
    def test_check_alert_status(self):
        self.assertEqual(bmsReceiver.invoke_alert_to_console('Temperature', -20),'TOO_LOW')
        self.assertEqual(bmsReceiver.invoke_alert_to_console('SOC', 90), 'TOO_HIGH')
        
    def test_convert_to_dictionary(self):
        console_data = json.dumps({'Temperature': 80.4, 'SOC': 49.5})
        bms_data = bmsReceiver.convert_to_dictionary(console_data)
        self.assertEqual(type(bms_data), dict)
        
if __name__ == '__main__':
  bmsReceiver = bmsReceiver()
  bms_param = {'Temperature': [30,45.5,67,83,92.7,45.34,34,12], 
                     'SOC': [32,34.45,23.23,12,43,54,65,43.5] }  
  unittest.main()