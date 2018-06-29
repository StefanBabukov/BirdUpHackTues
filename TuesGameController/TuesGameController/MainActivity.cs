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

            var buttonSwitch = FindViewById<Button>(Resource.Id.Button1);
            var buttonAttack = FindViewById<Button>(Resource.Id.ButtonA);
            var buttonRight = FindViewById<Button>(Resource.Id.ButtonR);
            var buttonLeft = FindViewById<Button>(Resource.Id.ButtonL);
            //var myButtonRight = new CustomButton();
            //myButtonRight.Text = "RightM";
            //myButtonRight.HorizontalOptions = Xamarin.Forms.LayoutOptions.FillAndExpand;

            //var myButtonLeft = new CustomButton();
            //myButtonLeft.Text = "LeftM";
            //myButtonLeft.HorizontalOptions = Xamarin.Forms.LayoutOptions.FillAndExpand;
            BluetoothConnection.ButtonMove(9);
            buttonSwitch.Click += (s, ea) =>
            {
                BluetoothConnection.ButtonMove(6);
            };

            //myButtonRight.MyOnPressed += (s, ea) =>
            //{
            //    newConnection.ButtonMove(1);
            //};
            //myButtonLeft.MyOnPressed += (s, ea) =>
            //{
            //    newConnection.ButtonMove(2);
            //};
            buttonAttack.Click += (s, ea) =>
            {
                BluetoothConnection.ButtonMove(5);
            };
            buttonLeft.Touch += (s, ea) =>
            {
                if(ea.Event.Action == Android.Views.MotionEventActions.Down)
                {
                    BluetoothConnection.ButtonMove(1); //start
                }
                else if(ea.Event.Action == Android.Views.MotionEventActions.Up)
                {
                    BluetoothConnection.ButtonMove(2); //stop
                }
            };
            buttonRight.Touch += (s, ea) =>
            {
                if (ea.Event.Action == Android.Views.MotionEventActions.Down)
                {
                    BluetoothConnection.ButtonMove(3); //start
                    //Toast.MakeText(this, "3", ToastLength.Short).Show();
                }
                else if (ea.Event.Action == Android.Views.MotionEventActions.Up)
                {
                    BluetoothConnection.ButtonMove(4); //stop
                    //Toast.MakeText(this, "4", ToastLength.Short).Show();
                }
            };
            //LinearLayout linearLayout = FindViewById<LinearLayout>(Resource.Id.linear);
            //linearLayout.AddView(myButtonLeft);
        }
    }
}

