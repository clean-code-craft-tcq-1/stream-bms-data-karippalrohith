# -*- coding: utf-8 -*-
"""
Created on Wed Jun 16 14:29:47 2021

@author: UGU3KOR
"""
import sys
import json
from bmsReceiverConstants import MA_WINDOW_SIZE
from bmsReceiverConstants import bms_param_thresholds     

class bmsReceiver():
    def __init__(self):
        self.total_records = None
        self.bms_param = {}
        
    def fetch_and_check_sender_data(self):
        bms_data = {}
        for console_data in sys.stdin:
            if console_data:
                bms_data = self.convert_to_dictionary(console_data)
                self.check_and_alert(bms_data)
    
    def check_and_alert(self, bms_data):
        for key, value in bms_data.items():
            self.check_threshold_for_param_exits_and_invoke_alert(key, value[-1])            
        print('-------------------------------------------------')
        
    def check_threshold_for_param_exits_and_invoke_alert(self, key, value):
        if key in bms_param_thresholds:
            self.invoke_alert_to_console(key, value)
        return 
            
    def invoke_alert_to_console(self, key, value):
        if value < bms_param_thresholds[key]['min']:
            print('ALERT! {} is too Low'.format(key))
        elif value > bms_param_thresholds[key]['max']:
            print('ALERT! {} is too high'.format(key))
                    
    def create_bms_param(self, key, value):
        if key not in self.bms_param:
            self.bms_param[key] = [value]
        else:
            self.bms_param[key].append(value)
        return 
                
    def convert_to_dictionary(self, param):
        bms_param = json.loads(param)
        for key, value in bms_param.items():
            self.create_bms_param(key, value)
        self.total_records = len(self.bms_param['Temperature'])
        return self.bms_param
        
    def calculate_moving_average(self, bms_param):
        moving_averages = {}
        for key, value in  bms_param.items():
            if key not in moving_averages:
                moving_average = sum(value[-5:]) / MA_WINDOW_SIZE
                moving_averages[key] = moving_average
            
        return moving_averages

    def min_max_calculator(self, data):
        max_value = max(data)
        min_value = min(data)
        return max_value, min_value
    
    def print_moving_average_to_console(self, moving_averages_dic):
        for key in self.bms_param.keys():
            print('Calculated Moving Average for last 5 values of {} is: {}'.format(key, moving_averages_dic[key]))
    
    def print_min_max_values_to_console(self):
        for param, value in self.bms_param.items():
            max_value, min_value = self.min_max_calculator(value)
            print('{} : '.format(param))
            print('Minimum Value: {}'.format(min_value))
            print('Maximum Value: {}'.format(max_value))
    
    def print_to_console(self):
        if self.bms_param is not None:
            moving_averages = self.calculate_moving_average(self.bms_param)
            self.print_moving_average_to_console(moving_averages)
            self.print_min_max_values_to_console()     
            
if __name__ == '__main__':
       
    bmsReceiver = bmsReceiver()
    bmsReceiver.fetch_and_check_sender_data()
    bmsReceiver.print_to_console()
