using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using TuesGameController;
using Xamarin.Forms;
using Xamarin.Forms.Platform.Android;

[assembly: ExportRenderer(typeof(Button), typeof(CustomButtonRenderer))]
namespace TuesGameController
{
    public class CustomButtonRenderer : ButtonRenderer
    {
        public CustomButtonRenderer(Context context)
            : base(context)
        {
        }

        protected override void OnElementChanged(ElementChangedEventArgs<Button> e)
        {
            base.OnElementChanged(e);
            var customButton = e.NewElement as CustomButton;
            var controlButton = Control as Android.Widget.Button;

            controlButton.Touch += (s, ea) =>
            {
                if (ea.Event.Action == MotionEventActions.Down)
                {
                    customButton.MyOnPressedM();
                }
                else if (ea.Event.Action == MotionEventActions.Up)
                {
                    customButton.MyOnReleasedM();
                }
            };
        }
    }
}