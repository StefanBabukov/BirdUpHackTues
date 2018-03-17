﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Android.App;
using Android.Bluetooth;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Util;
using Android.Views;
using Android.Widget;

namespace TuesGameController
{
    public class BluetoothConnection
    {
        private const string UUID = "00001101-0000-1000-8000-00805f9b34fb";
        public BluetoothConnection()
        {
            this.MobAdapter = BluetoothAdapter.DefaultAdapter; //Take the adapter
            if(this.MobAdapter == null)
            {
                return;
            }
            try
            {
                this.ArDevice = (from bondedDevice in this.MobAdapter.BondedDevices where bondedDevice.Name == "HC-05\n\n" select bondedDevice).FirstOrDefault();
            }
            catch(NullReferenceException)
            {
                throw new NullReferenceException("Sequence returned null!");
            }

        }

        private BluetoothDevice ArDevice; //The remote bluetooth device.
        private BluetoothAdapter MobAdapter; //Local device
        private BluetoothSocket MobSocket; //Serial Port Profile for streaming transport over Bluetooth.

        public void Connect()
        {
            if (this.ArDevice == null) return;
            this.MobSocket = this.ArDevice.CreateRfcommSocketToServiceRecord(Java.Util.UUID.FromString(UUID));
            this.MobAdapter.CancelDiscovery();
            //if (this.MobSocket == null) return;
            this.MobSocket.Connect();
        }

        public void Disconnect()
        {
            //TO DO
        }

    }
}