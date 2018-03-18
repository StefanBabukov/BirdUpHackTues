using Android.App;
using Android.Widget;
using Android.OS;
using System;
using Android.Content.PM;
using Android.Bluetooth;

namespace TuesGameController
{
    [Activity(Label = "TuesGameController", ConfigurationChanges = ConfigChanges.ScreenSize | ConfigChanges.Orientation,
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
            var buttonRight = FindViewById<Button>(Resource.Id.ButtonR);
            var buttonLeft = FindViewById<Button>(Resource.Id.ButtonL);
            var buttonAttack = FindViewById<Button>(Resource.Id.ButtonA);
            var text = FindViewById<TextView>(Resource.Id.textView1);
            buttonConnect.Click += (s, ea) =>
            {
                newConnection.Connect();
                text.Text = "Connected!";
                //Toast.MakeText(this, "CONNECTED", ToastLength.Long).Show();
            };

            buttonRight.Click += (s, ea) =>
            {
                newConnection.ButtonMove(1);
            };
            buttonLeft.Click += (s, ea) =>
            {
                newConnection.ButtonMove(2);
            };
            buttonAttack.Click += (s, ea) =>
            {
                newConnection.ButtonMove(3);
            };
        }
    }
}

