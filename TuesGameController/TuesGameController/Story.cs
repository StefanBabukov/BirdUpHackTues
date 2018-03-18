using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;

namespace TuesGameController
{
    [Activity(Label = "Story", MainLauncher = true)]
    public class Story : Activity
    {
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);
            SetContentView(Resource.Layout.Prologue);
            var buttonProceed = FindViewById<Button>(Resource.Id.buttonTU);
            buttonProceed.Click += (s, ea) =>
            {
                StartActivity(typeof(MainActivity));
            };

            // Create your application here
        }
    }
}