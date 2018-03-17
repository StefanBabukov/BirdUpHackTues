using Android.App;
using Android.Widget;
using Android.OS;
using System;
using Android.Content.PM;
using Android.Bluetooth;

namespace TuesGameController
{
    [Activity(Label = "TuesGameController", MainLauncher = true, ConfigurationChanges = ConfigChanges.ScreenSize | ConfigChanges.Orientation,
    ScreenOrientation = ScreenOrientation.Landscape)]
    public class MainActivity : Activity
    {
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);

            // Set our view from the "main" layout resource
            SetContentView(Resource.Layout.Main);

            BluetoothConnection newConnection = new BluetoothConnection();

            var buttonConnect = FindViewById<Button>(Resource.Id.Button1);
            var text = FindViewById<TextView>(Resource.Id.textView1);
            buttonConnect.Click += (s, ea) =>
            {
                text.Text = "Connecting!";
                newConnection.Connect();
                text.Text = "Connected!";
                //Toast.MakeText(this, "CONNECTED", ToastLength.Long).Show();
            };
        }
    }
}

