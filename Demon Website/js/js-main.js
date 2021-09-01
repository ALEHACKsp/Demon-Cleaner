

(function($) {

	var	$window = $(window),
		$body = $('body'),
		$sidebar = $('#sidebar');

		breakpoints({
			xlarge:   [ '1281px',  '1680px' ],
			large:    [ '981px',   '1280px' ],
			medium:   [ '737px',   '980px'  ],
			small:    [ '481px',   '736px'  ],
			xsmall:   [ null,      '480px'  ]
		});

		if (browser.name == 'ie')
			$body.addClass('is-ie');

		$window.on('load', function() {
			window.setTimeout(function() {
				$body.removeClass('is-preload');
			}, 100);
		});


			$('form').on('click', '.submit', function(event) {

					event.stopPropagation();
					event.preventDefault();

					$(this).parents('form').submit();

			});

		if ($sidebar.length > 0) {

			var $sidebar_a = $sidebar.find('a');

			$sidebar_a
				.addClass('scrolly')
				.on('click', function() {

					var $this = $(this);

						if ($this.attr('href').charAt(0) != '#')
							return;

						$sidebar_a.removeClass('active');

						$this
							.addClass('active')
							.addClass('active-locked');

				})
				.each(function() {

					var	$this = $(this),
						id = $this.attr('href'),
						$section = $(id);

						if ($section.length < 1)
							return;

						$section.scrollex({
							mode: 'middle',
							top: '-20vh',
							bottom: '-20vh',
							initialize: function() {

									$section.addClass('inactive');

							},
							enter: function() {

									$section.removeClass('inactive');

									if ($sidebar_a.filter('.active-locked').length == 0) {

										$sidebar_a.removeClass('active');
										$this.addClass('active');

									}

									else if ($this.hasClass('active-locked'))
										$this.removeClass('active-locked');

							}
						});

				});

		}

		$('.scrolly').scrolly({
			speed: 1000,
			offset: function() {

					if (breakpoints.active('<=large')
					&&	!breakpoints.active('<=small')
					&&	$sidebar.length > 0)
						return $sidebar.height();

				return 0;

			}
		});

		$('.spotlights > section')
			.scrollex({
				mode: 'middle',
				top: '-10vh',
				bottom: '-10vh',
				initialize: function() {

						$(this).addClass('inactive');

				},
				enter: function() {

						$(this).removeClass('inactive');

				}
			})
			.each(function() {

				var	$this = $(this),
					$image = $this.find('.image'),
					$img = $image.find('img'),
					x;

					$image.css('background-image', 'url(' + $img.attr('src') + ')');

					if (x = $img.data('position'))
						$image.css('background-position', x);

					$img.hide();

			});

		$('.features')
			.scrollex({
				mode: 'middle',
				top: '-20vh',
				bottom: '-20vh',
				initialize: function() {

						$(this).addClass('inactive');

				},
				enter: function() {

						$(this).removeClass('inactive');

				}
			});

})(jQuery);