using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Xamarin.Forms;

namespace TuesGameController
{
    public class CustomButton : Button
    {
        public event EventHandler MyOnPressed;
        public event EventHandler MyOnReleased;

        public void MyOnPressedM()
        {
            this.MyOnPressed?.Invoke(this, EventArgs.Empty);
        }

        public void MyOnReleasedM()
        {
            this.MyOnReleased?.Invoke(this, EventArgs.Empty);
        }
    }
}